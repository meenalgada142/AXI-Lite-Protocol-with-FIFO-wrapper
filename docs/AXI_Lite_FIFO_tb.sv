`timescale 1ns/1ps

module axi_lite_fifo_tb;

  // Clock and reset generation
  logic ACLK = 0;
  logic ARESETn = 0;
  always #5 ACLK = ~ACLK;  // 100 MHz clock

  // AXI-Lite signal declarations
  logic [31:0] AWADDR, WDATA, ARADDR;
  logic        AWVALID, WVALID, BREADY, ARVALID, RREADY;
  logic        AWREADY, WREADY, BVALID, ARREADY, RVALID;
  logic [1:0]  BRESP, RRESP;
  logic [31:0] RDATA;

  // DUT: AXI-Lite wrapper around FIFO
  axi_lite_fifo_wrapper dut (
    .ACLK(ACLK), .ARESETn(ARESETn),
    .AWADDR(AWADDR), .AWVALID(AWVALID), .AWREADY(AWREADY),
    .WDATA(WDATA), .WVALID(WVALID), .WREADY(WREADY),
    .BRESP(BRESP), .BVALID(BVALID), .BREADY(BREADY),
    .ARADDR(ARADDR), .ARVALID(ARVALID), .ARREADY(ARREADY),
    .RDATA(RDATA), .RRESP(RRESP), .RVALID(RVALID), .RREADY(RREADY)
  );

  // AXI-Lite master driver: reusable transaction module
  axi_lite_master_driver driver (
    .clk(ACLK), .rst(~ARESETn),
    .AWADDR(AWADDR), .AWVALID(AWVALID), .AWREADY(AWREADY),
    .WDATA(WDATA), .WVALID(WVALID), .WREADY(WREADY),
    .BRESP(BRESP), .BVALID(BVALID), .BREADY(BREADY),
    .ARADDR(ARADDR), .ARVALID(ARVALID), .ARREADY(ARREADY),
    .RDATA(RDATA), .RRESP(RRESP), .RVALID(RVALID), .RREADY(RREADY)
  );

  // Test sequence
  initial begin
    $display("Starting AXI-Lite FIFO test...");

    // Apply reset
    ARESETn = 0;
    repeat (5) @(posedge ACLK);
    ARESETn = 1;

    // Push 3 values into FIFO using AXI-Lite write transactions
    // Address 0x00 is mapped to FIFO write port
    driver.axi_write(32'h0000_0000, 8'hA1);  // Push A1
    driver.axi_write(32'h0000_0000, 8'hB2);  // Push B2
    driver.axi_write(32'h0000_0000, 8'hC3);  // Push C3

    //This is a AXI_lite_tb_sv i.e. UVM testbench
    // Pop 2 values from FIFO using AXI-Lite read transactions
    // Address 0x04 is mapped to FIFO read port
    logic [31:0] val;
    driver.axi_read(32'h0000_0004, val); $display("Read: %h", val);  // Expect A1
    driver.axi_read(32'h0000_0004, val); $display("Read: %h", val);  // Expect B2

    // Read FIFO status from address 0x08
    // Bit 1 = full, Bit 0 = empty
    driver.axi_read(32'h0000_0008, val);
    $display("Status: full=%0b, empty=%0b", val[1], val[0]);

    // End simulation
    $finish;
  end

endmodule
