#include "driver.h"
#include "monitor.h"
#include "coverage_tracker.h"
#include "Vdut.h"
#include <iostream>
#include "sim_utils.h"
#include "globals.h"

// External references from tb_top
extern vluint64_t main_time;
extern VerilatedVcdC* tfp;
extern Vdut* dut;

/**
 * @brief Tick the simulation and sample monitor before and after.
 */
void tick_and_sample() {
    monitor->sample();   // ✅ Sample before tick
    tick(dut, tfp);      // ✅ Advance simulation
    monitor->sample();   // ✅ Sample after tick
    // log_handshakes(dut);  // ✅ Optional debug
}

/**
 * @brief Run a sequence of AXI-Lite writes and reads to exercise FIFO.
 *        Pushes 16 values into the FIFO, pops 3, and reads status.
 */
void run_fifo_sequence(AxiLiteDriver& driver) {
    std::cout << "Pushing 16 values into FIFO...\n";

    //=======================
    // Write 16 values into FIFO
    //=======================
    driver.write(0x00, 0xA1);
    tick_and_sample(); tick_and_sample();

    driver.write(0x00, 0x00);
    tick_and_sample(); tick_and_sample();

    driver.write(0x00, 0xC3);
    tick_and_sample(); tick_and_sample();

    driver.write(0x00, 0xB3);
    tick_and_sample(); tick_and_sample();

    driver.write(0x00, 0xFFFFFFFF);
    tick_and_sample(); tick_and_sample();

    driver.write(0x00, 0xFFFFFFFF);
    tick_and_sample(); tick_and_sample();

    driver.write(0x00, 0xFFFFFFFF);
    tick_and_sample(); tick_and_sample();

    driver.write(0x00, 0xFFFFFFFF);
    tick_and_sample(); tick_and_sample();

    driver.write(0x00, 0xFFFFFFFF);
    tick_and_sample(); tick_and_sample();

    driver.write(0x00, 0xFFFFFFFF);
    tick_and_sample(); tick_and_sample();

    driver.write(0x00, 0xFFFFFFFF);
    tick_and_sample(); tick_and_sample();

    driver.write(0x00, 0xFFFFFFFF);
    tick_and_sample(); tick_and_sample();

    driver.write(0x00, 0xFFFFFBFF);
    tick_and_sample(); tick_and_sample();

    driver.write(0x00, 0xFFFFFAFF);
    tick_and_sample(); tick_and_sample();

    driver.write(0x00, 0xFFFFFEFF);
    tick_and_sample(); tick_and_sample();

    driver.write(0x00, 0xFFFFFCFF);
    tick_and_sample(); tick_and_sample();

    // driver.write(0x00, 0x00);
    // tick_and_sample(); tick_and_sample();

    //=======================
    // Read 3 values from FIFO
    //=======================
    std::cout << "Popping 3 values from FIFO...\n";

    uint32_t val1 = driver.read(0x10);
    tick_and_sample(); tick_and_sample();

    uint32_t val2 = driver.read(0x10);
    tick_and_sample(); tick_and_sample();

    uint32_t val3 = driver.read(0x10);
    tick_and_sample(); tick_and_sample();

    std::cout << "Read: 0x" << std::hex << val1
              << ", 0x" << val2
              << ", 0x" << val3 << std::dec << "\n";

    //=======================
    // Read FIFO status register
    //=======================
    std::cout << "Reading FIFO status...\n";
    uint32_t status = driver.read(0x20);
    tick_and_sample(); tick_and_sample();

    std::cout << "Status: full=" << ((status >> 1) & 1)
              << ", empty=" << (status & 1) << "\n";


    std::cout << "Read: 0x" << std::hex << val1
          << ", 0x" << val2
          << ", 0x" << val3 << std::dec << "\n";
    
    uint32_t val4 = driver.read(0x80);
    tick_and_sample(); tick_and_sample(); 
    std::cout << "Read (val4): 0x" << std::hex << val4 << std::dec << "\n";
        
}
