#include "axi_lite_driver.h"

void AxiLiteDriver::write(uint32_t addr, uint32_t data) {
    dut->AWADDR = addr;
    dut->WDATA  = data;
    dut->AWVALID = 1;
    dut->WVALID  = 1;
    dut->BREADY  = 1;

    while (!(dut->AWREADY && dut->WREADY)) {
        dut->ACLK ^= 1; *main_time += 5; dut->eval();
    }

    dut->AWVALID = 0;
    dut->WVALID  = 0;

    while (!dut->BVALID) {
        dut->ACLK ^= 1; *main_time += 5; dut->eval();
    }

    dut->BREADY = 0;
}

uint32_t AxiLiteDriver::read(uint32_t addr) {
    dut->ARADDR = addr;
    dut->ARVALID = 1;
    dut->RREADY  = 1;

    while (!dut->ARREADY) {
        dut->ACLK ^= 1; *main_time += 5; dut->eval();
    }

    dut->ARVALID = 0;

    while (!dut->RVALID) {
        dut->ACLK ^= 1; *main_time += 5; dut->eval();
    }

    uint32_t val = dut->RDATA;
    dut->RREADY = 0;
    return val;
}







#include "axi_lite_driver.h"

void AxiLiteDriver::write(uint32_t addr, uint32_t data) {
    dut->AWADDR = addr;
    dut->WDATA  = data;
    dut->AWVALID = 1;
    dut->WVALID  = 1;
    dut->BREADY  = 1;

    while (!(dut->AWREADY && dut->WREADY)) {
        dut->ACLK ^= 1; *main_time += 5; dut->eval();
    }

    dut->AWVALID = 0;
    dut->WVALID  = 0;

    while (!dut->BVALID) {
        dut->ACLK ^= 1; *main_time += 5; dut->eval();
    }

    dut->BREADY = 0;
}

uint32_t AxiLiteDriver::read(uint32_t addr) {
    dut->ARADDR = addr;
    dut->ARVALID = 1;
    dut->RREADY  = 1;

    while (!dut->ARREADY) {
        dut->ACLK ^= 1; *main_time += 5; dut->eval();
    }

    dut->ARVALID = 0;

    while (!dut->RVALID) {
        dut->ACLK ^= 1; *main_time += 5; dut->eval();
    }

    uint32_t val = dut->RDATA;
    dut->RREADY = 0;
    return val;
}


#include "axi_lite_monitor.h"
#include <iostream>

void AxiLiteMonitor::sample() {
    // Sample write response
    if (dut->BVALID && dut->BREADY) {
        AxiWriteResp wr;
        wr.addr = dut->AWADDR;
        wr.data = dut->WDATA;
        wr.resp = dut->BRESP;
        write_log.push_back(wr);
        std::cout << "[MONITOR @ " << *main_time << "ns] WriteResp: addr=0x"
                  << std::hex << wr.addr << ", data=0x" << wr.data
                  << ", resp=" << (int)wr.resp << std::endl;
    }

    // Sample read response
    if (dut->RVALID && dut->RREADY) {
        AxiReadResp rd;
        rd.addr = dut->ARADDR;
        rd.data = dut->RDATA;
        rd.resp = dut->RRESP;
        read_log.push_back(rd);
        std::cout << "[MONITOR @ " << *main_time << "ns] ReadResp: addr=0x"
                  << std::hex << rd.addr << ", data=0x" << rd.data
                  << ", resp=" << (int)rd.resp << std::endl;
    }
}

void AxiLiteMonitor::print_logs() {
    std::cout << "\n=== AXI-Lite Write Log ===\n";
    for (const auto& wr : write_log) {
        std::cout << "  addr=0x" << std::hex << wr.addr
                  << ", data=0x" << wr.data
                  << ", resp=" << std::dec << (int)wr.resp << "\n";
    }

    std::cout << "\n=== AXI-Lite Read Log ===\n";
    for (const auto& rd : read_log) {
        std::cout << "  addr=0x" << std::hex << rd.addr
                  << ", data=0x" << rd.data
                  << ", resp=" << std::dec << (int)rd.resp << "\n";
    }
}



#pragma once
#include "Vdut.h"
#include <vector>
#include <string>

struct AxiWriteResp {
    uint32_t addr;
    uint32_t data;
    uint8_t  resp;
};

struct AxiReadResp {
    uint32_t addr;
    uint32_t data;
    uint8_t  resp;
};

class AxiLiteMonitor {
public:
    Vdut* dut;
    vluint64_t* main_time;

    std::vector<AxiWriteResp> write_log;
    std::vector<AxiReadResp>  read_log;

    AxiLiteMonitor(Vdut* d, vluint64_t* t) : dut(d), main_time(t) {}

    void sample();
    void print_logs();
};



#include "axi_lite_driver.h"
#include <iostream>

void run_fifo_sequence(AxiLiteDriver& driver) {
    std::cout << "Pushing 3 values into FIFO...\n";
    driver.write(0x00, 0xA1);
    driver.write(0x00, 0xB2);
    driver.write(0x00, 0xC3);

    std::cout << "Popping 2 values from FIFO...\n";
    uint32_t val1 = driver.read(0x04);
    uint32_t val2 = driver.read(0x04);
    std::cout << "Read: " << std::hex << val1 << ", " << val2 << "\n";

    std::cout << "Reading FIFO status...\n";
    uint32_t status = driver.read(0x08);
    std::cout << "Status: full=" << ((status >> 1) & 1)
              << ", empty=" << (status & 1) << "\n";
}





#include "Vdut.h"
#include "verilated.h"
#include "axi_lite_driver.h"
#include "axi_lite_monitor.h"

// Forward declaration of your test sequence
extern void run_fifo_sequence(AxiLiteDriver&);

// Global simulation time
vluint64_t main_time = 0;
double sc_time_stamp() { return main_time; }

int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Vdut* dut = new Vdut;

    // Clock and reset
    dut->ACLK = 0;
    dut->ARESETn = 0;

    // Create driver and monitor
    AxiLiteDriver driver(dut, &main_time);
    AxiLiteMonitor monitor(dut, &main_time);

    // Apply reset
    for (int i = 0; i < 10; ++i) {
        dut->ACLK ^= 1;
        main_time += 5;
        dut->eval();
    }
    dut->ARESETn = 1;

    // Run test sequence (push/pop/status)
    run_fifo_sequence(driver);

    // Sample for a few extra cycles to catch final responses
    for (int i = 0; i < 20; ++i) {
        dut->ACLK ^= 1;
        main_time += 5;
        dut->eval();
        monitor.sample();  // Monitor AXI-Lite responses
    }

    // Print captured logs
    monitor.print_logs();

    // Finish simulation
    dut->final();
    delete dut;
    return 0;
}
