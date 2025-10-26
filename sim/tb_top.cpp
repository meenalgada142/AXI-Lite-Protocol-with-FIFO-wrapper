#include "Vdut.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "driver.h"
#include "monitor.h"
#include "coverage_tracker.h"
#include "sim_utils.h"
#include "globals.h"

//============================================================
// Forward declaration of your test sequence
//============================================================
extern void run_fifo_sequence(AxiLiteDriver&);

//============================================================
// Global simulation time
//============================================================
vluint64_t main_time = 0;
double sc_time_stamp() { return main_time; }

//============================================================
// Define global variables declared in globals.h
//============================================================
Vdut* dut = nullptr;
VerilatedVcdC* tfp = nullptr;
AxiLiteMonitor* monitor = nullptr;

//============================================================
// Clock tick with waveform dump
//============================================================
void tick(Vdut* dut, VerilatedVcdC* tfp) {
    dut->ACLK ^= 1;         // Toggle clock
    main_time += 5;         // Advance time
    dut->eval();            // Evaluate DUT
    if (tfp) tfp->dump(main_time);  // Dump waveform if enabled
}

//============================================================
// Handshake logger (optional debug utility)
//============================================================
void log_handshakes(Vdut* dut) {
    std::cout << "AWVALID=" << (int)dut->AWVALID << " AWREADY=" << (int)dut->AWREADY
              << " | WVALID=" << (int)dut->WVALID << " WREADY=" << (int)dut->WREADY
              << " | BVALID=" << (int)dut->BVALID << " BREADY=" << (int)dut->BREADY << std::endl;

    std::cout << "ARVALID=" << (int)dut->ARVALID << " ARREADY=" << (int)dut->ARREADY
              << " | RVALID=" << (int)dut->RVALID << " RREADY=" << (int)dut->RREADY << std::endl;
}

//============================================================
// Main simulation entry point
//============================================================
int main(int argc, char** argv) {
    Verilated::commandArgs(argc, argv);
    Verilated::traceEverOn(true);

    //=======================
    // DUT and waveform setup
    //=======================
    dut = new Vdut;
    tfp = new VerilatedVcdC;
    dut->trace(tfp, 99);
    tfp->open("wave.vcd");

    //=======================
    // Initial reset
    //=======================
    dut->ACLK = 0;
    dut->ARESETn = 0;

    //=======================
    // Driver, monitor, coverage setup
    //=======================
    CoverageTracker coverage;
    AxiLiteDriver driver(dut, &main_time, tfp);  // ✅ Pass tfp to driver
    driver.verbose = true;
    monitor = new AxiLiteMonitor(dut, &main_time, &coverage);  // ✅ Assign global pointer

    std::cout << "[INFO] Applying reset..." << std::endl;
    for (int i = 0; i < 50; ++i) tick(dut, tfp);

    dut->ARESETn = 1;
    tick(dut, tfp);  // ✅ Propagate reset release
    for (int i = 0; i < 5; ++i) tick(dut, tfp);  // Optional: settle logic

    std::cout << "[INFO] Reset released." << std::endl;

    //=======================
    // Run test sequence
    //=======================
    std::cout << "[INFO] Running FIFO sequence..." << std::endl;
    run_fifo_sequence(driver);  // ✅ Driver uses shared tick()

    //=======================
    // Post-sequence sampling
    //=======================
    std::cout << "[INFO] Sampling post-sequence responses..." << std::endl;

    //=======================
    // Final reports
    //=======================
    monitor->print_logs();
    coverage.report();

    //=======================
    // Cleanup
    //=======================
    dut->final();
    tfp->close();
    delete monitor;
    delete tfp;
    delete dut;

    return 0;
}
