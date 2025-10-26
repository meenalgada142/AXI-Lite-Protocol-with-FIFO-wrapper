#include "monitor.h"
#include <iostream>

/**
 * @brief Sample DUT signals to detect completed AXI-Lite transactions.
 * Logs write/read responses and updates coverage bins.
 */
void AxiLiteMonitor::sample() {
    // Optional clock edge sampling (not used currently)
    // static int last_clk = 1;  // Assume clock starts high
    // int current_clk = dut->ACLK;

    //============================================================
    // ✅ Sample write response (BVALID & BREADY)
    //============================================================
    // if (last_clk == 1 && current_clk == 0) {
    if (dut->BVALID && dut->BREADY) {
        AxiWriteResp wr;
        wr.addr = dut->AWADDR;
        wr.data = dut->WDATA;
        wr.resp = dut->BRESP;
        write_log.push_back(wr);

        std::cout << "[MONITOR @ " << *main_time << "ns] WriteResp: addr=0x"
                  << std::hex << wr.addr << ", data=0x" << wr.data
                  << ", BRESP=" << std::dec << (int)wr.resp << std::endl;
        // std::cout << "[MONITOR] FIFO level = " << dut->fifo_level << "\n";

        // ✅ Coverage hook for write transaction
        if (coverage) {
            coverage->sample_transaction(false, wr.addr, wr.data);

            // Error classification
            if (wr.resp == 2) coverage->sample_error(false, true);   // SLVERR → corrupted or full
            else if (wr.resp == 3) coverage->sample_error(true, false);  // DECERR → invalid address
        }
    }

    //============================================================
    // ✅ Sample read response (RVALID & RREADY)
    //============================================================
    // if (last_clk == 1 && current_clk == 0) {
    if (dut->RVALID && dut->RREADY) {
        AxiReadResp rd;
        rd.addr = dut->ARADDR;
        rd.data = dut->RDATA;
        rd.resp = dut->RRESP;
        read_log.push_back(rd);

        std::cout << "[MONITOR @ " << *main_time << "ns] ReadResp: addr=0x"
                  << std::hex << rd.addr << ", data=0x" << rd.data
                  << ", RRESP=" << std::dec << (int)rd.resp << std::endl;

        // ✅ Coverage hook for read transaction
        if (coverage) {
            coverage->sample_transaction(true, rd.addr, rd.data);

            // Error classification
            if (rd.resp == 2) coverage->sample_error(false, true);   // SLVERR → empty or corrupted
            else if (rd.resp == 3) coverage->sample_error(true, false);  // DECERR → bad address
        }
    }

    //============================================================
    // ✅ Sample FIFO depth for functional coverage
    //============================================================
    if (dut->AWVALID || dut->WVALID || dut->ARVALID || dut->RVALID || dut->BVALID) {
        coverage->sample_fifo_depth(dut->fifo_level, 16);
    }
}

/**
 * @brief Print all logged AXI-Lite transactions.
 */
void AxiLiteMonitor::print_logs() {
    std::cout << "\n=== AXI-Lite Write Log ===\n";
    for (const auto& wr : write_log) {
        std::cout << "  addr=0x" << std::hex << wr.addr
                  << ", data=0x" << wr.data
                  << ", BRESP=" << std::dec << (int)wr.resp << "\n";
    }

    std::cout << "\n=== AXI-Lite Read Log ===\n";
    for (const auto& rd : read_log) {
        std::cout << "  addr=0x" << std::hex << rd.addr
                  << ", data=0x" << rd.data
                  << ", RRESP=" << std::dec << (int)rd.resp << "\n";
    }
}
