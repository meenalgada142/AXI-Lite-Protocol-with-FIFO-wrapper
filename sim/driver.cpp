#include "driver.h"
#include <iostream>
#include <iomanip>
#include "monitor.h"
#include "globals.h"

//============================================================
// Toggle clock and advance simulation time
//============================================================
void AxiLiteDriver::tick() {
    dut->ACLK ^= 1;         // Toggle clock
    *main_time += 5;        // Advance time
    dut->eval();            // Evaluate DUT
    if (tfp) tfp->dump(*main_time);  // Dump waveform if enabled
}

//============================================================
// AXI-Lite Write Transaction
//============================================================
void AxiLiteDriver::write(uint32_t addr, uint32_t data) {
    if (verbose) {
        std::cout << "[WRITE] Addr: 0x" << std::hex << addr
                  << ", Data: 0x" << data << std::dec << std::endl;
    }

    // Initiate write address and data phase
    dut->AWADDR  = addr;
    dut->WDATA   = data;
    dut->AWVALID = 1;
    dut->WVALID  = 1;
    dut->eval();
    tick(); tick();

    // Wait for AWREADY and WREADY handshake
    int timeout = 200;
    while (!(dut->AWREADY && dut->WREADY) && timeout--) tick();
    if (timeout <= 0) {
        std::cerr << "[ERROR] Timeout during AWREADY/WREADY handshake\n";
        return;
    }

    // Deassert valid signals
    dut->AWVALID = 0;
    dut->WVALID  = 0;
    dut->eval();
    tick();

    // Wait for BVALID response
    timeout = 200;
    while (!dut->BVALID && timeout--) tick();
    if (timeout <= 0) {
        std::cerr << "[ERROR] Timeout during BVALID response\n";
        return;
    }

    // Accept response
    dut->BREADY = 1;
    monitor->sample();  // ✅ Sample coverage after write completes
    tick(); tick();
    dut->BREADY = 0;

    // Check BRESP for errors
    if (dut->BRESP != 0) {
        std::cerr << "[ERROR] BRESP = " << int(dut->BRESP) << " (Write failed)\n";
    }
}

//============================================================
// AXI-Lite Read Transaction
//============================================================
uint32_t AxiLiteDriver::read(uint32_t addr) {
    if (verbose) {
        std::cout << "[READ] Addr: 0x" << std::hex << addr << std::dec << std::endl;
    }

    // Initiate read address phase
    dut->ARADDR  = addr;
    dut->ARVALID = 1;
    dut->eval();
    tick(); tick();

    // Wait for ARREADY handshake
    int timeout = 200;
    while (!dut->ARREADY && timeout--) tick();
    if (timeout <= 0) {
        std::cerr << "[ERROR] Timeout during ARREADY handshake\n";
        return 0xFFFFFFFF;
    }

    tick();
    dut->ARVALID = 0;
    dut->eval();
    tick();

    // Wait for RVALID response
    timeout = 200;
    while (!dut->RVALID && timeout--) tick();
    if (timeout <= 0) {
        std::cerr << "[ERROR] Timeout during RVALID response\n";
        return 0xFFFFFFFF;
    }

    // Accept read data
    dut->RREADY = 1;
    monitor->sample();  // ✅ Sample coverage after read completes
    tick(); tick();
    dut->RREADY = 0;

    // Capture read value
    uint32_t val = dut->RDATA;

    // Check RRESP for errors
    if (dut->RRESP != 0) {
        std::cerr << "[ERROR] RRESP = " << int(dut->RRESP) << " (Read failed)\n";
    }

    return val;
}

//============================================================
// Burst Write: multiple sequential writes
//============================================================
void AxiLiteDriver::burst_write(uint32_t base_addr, const std::vector<uint32_t>& data) {
    for (size_t i = 0; i < data.size(); ++i) {
        write(base_addr + i * 4, data[i]);  // 4-byte stride
    }
}

//============================================================
// Burst Read: multiple sequential reads
//============================================================
std::vector<uint32_t> AxiLiteDriver::burst_read(uint32_t base_addr, size_t count) {
    std::vector<uint32_t> results;
    for (size_t i = 0; i < count; ++i) {
        results.push_back(read(base_addr + i * 4));  // 4-byte stride
    }
    return results;
}

//============================================================
// Inject protocol errors for coverage
//============================================================
void AxiLiteDriver::inject_error(uint32_t addr, uint32_t data, bool corrupt_data, bool invalid_addr) {
    if (invalid_addr) addr = 0xDEADBEEF;         // Use illegal address
    if (corrupt_data) data ^= 0xFFFFFFFF;        // Flip all bits

    if (verbose) {
        std::cout << "[ERROR INJECT] Addr: 0x" << std::hex << addr
                  << ", Data: 0x" << data << std::dec << std::endl;
    }

    write(addr, data);  // Injected write
}
