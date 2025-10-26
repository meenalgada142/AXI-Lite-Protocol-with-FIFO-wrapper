#include "coverage_tracker.h"
#include <iostream>
#include <iomanip>

//============================================================
// Sample a transaction (read or write) and bin address/data
//============================================================
void CoverageTracker::sample_transaction(bool is_read, uint32_t addr, uint32_t data) {
    // Count read vs write operations
    if (is_read) {
        read_count++;
    } else {
        write_count++;
    }

    //=======================
    // Address binning
    //=======================
    if (addr < 0x10) {
        addr_low++;      // Low address range: 0x00–0x0F
    } else if (addr < 0x80) {
        addr_mid++;      // Mid address range: 0x10–0x7F
    } else {
        addr_high++;     // High address range: 0x80 and above
    }

    //=======================
    // Data pattern binning
    //=======================
    if (data == 0x00000000) {
        data_zero++;     // All-zero data
    } else if (data == 0xFFFFFFFF) {
        data_ones++;     // All-one data
    } else if ((data & 0xAAAAAAAA) == 0xAAAAAAAA || 
               (data & 0x55555555) == 0x55555555) {
        data_alt++;      // Alternating bit pattern (e.g., 0xAA, 0x55)
    }

    //=======================
    // Optional debug print
    //=======================
    // std::cout << "[Coverage] Sampled " << (is_read ? "READ" : "WRITE")
    //           << " Addr: 0x" << std::hex << addr
    //           << " Data: 0x" << std::hex << data << std::dec << "\n";
}

//============================================================
// Sample FIFO depth and bin occupancy level
//============================================================
void CoverageTracker::sample_fifo_depth(size_t depth, size_t capacity) {
    if (depth == 0) {
        fifo_empty++;    // FIFO is empty
    } else if (depth >= capacity / 2 && depth < capacity) {
        fifo_half++;     // FIFO is half-full or more
    } else if (depth == capacity) {
        fifo_full++;     // FIFO is completely full
    }
}

//============================================================
// Sample error conditions: invalid address or corrupt data
//============================================================
void CoverageTracker::sample_error(bool invalid_addr, bool corrupt_data) {
    if (invalid_addr) {
        err_invalid_addr++;  // Address outside valid range
    }
    if (corrupt_data) {
        err_corrupt_data++;  // Data mismatch or corruption detected
    }
}

//============================================================
// Print a full coverage report to stdout
//============================================================
void CoverageTracker::report() const {
    std::cout << "\n=== Coverage Report ===\n";

    // Transaction counts
    std::cout << "Reads: " << read_count << ", Writes: " << write_count << "\n";

    // Address bin summary
    std::cout << "Address bins:\n";
    std::cout << "  Low (<0x10): " << addr_low << "\n";
    std::cout << "  Mid (<0x80): " << addr_mid << "\n";
    std::cout << "  High (>=0x80): " << addr_high << "\n";

    // Data pattern summary
    std::cout << "Data bins:\n";
    std::cout << "  Zero (0x00000000): " << data_zero << "\n";
    std::cout << "  Ones (0xFFFFFFFF): " << data_ones << "\n";
    std::cout << "  Alternating (0xAA/0x55): " << data_alt << "\n";

    // FIFO occupancy summary
    std::cout << "FIFO depth bins:\n";
    std::cout << "  Empty: " << fifo_empty << "\n";
    std::cout << "  Half-full: " << fifo_half << "\n";
    std::cout << "  Full: " << fifo_full << "\n";

    // Error condition summary
    std::cout << "Error bins:\n";
    std::cout << "  Invalid address: " << err_invalid_addr << "\n";
    std::cout << "  Corrupt data   : " << err_corrupt_data << "\n";
}
