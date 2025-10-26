module axi_lite_master_driver #(
    parameter ADDR_WIDTH = 32,
    parameter DATA_WIDTH = 32
)(
    input  logic                  clk,
    input  logic                  rst,

    // AXI-Lite Master Interface
    output logic [ADDR_WIDTH-1:0] AWADDR,
    output logic                  AWVALID,
    input  logic                  AWREADY,

    output logic [DATA_WIDTH-1:0] WDATA,
    output logic                  WVALID,
    input  logic                  WREADY,

    input  logic [1:0]            BRESP,
    input  logic                  BVALID,
    output logic                  BREADY,

    output logic [ADDR_WIDTH-1:0] ARADDR,
    output logic                  ARVALID,
    input  logic                  ARREADY,

    input  logic [DATA_WIDTH-1:0] RDATA,
    input  logic [1:0]            RRESP,
    input  logic                  RVALID,
    output logic                  RREADY
);

    // AXI-Lite Write Transaction
    task automatic axi_write(input logic [ADDR_WIDTH-1:0] addr, input logic [DATA_WIDTH-1:0] data);
        begin
            @(posedge clk);
            AWADDR  <= addr;
            WDATA   <= data;
            AWVALID <= 1;
            WVALID  <= 1;
            BREADY  <= 1;

            wait (AWREADY && WREADY);
            @(posedge clk);
            AWVALID <= 0;
            WVALID  <= 0;

            wait (BVALID);
            @(posedge clk);
            BREADY <= 0;
        end
    endtask

    // AXI-Lite Read Transaction
    task automatic axi_read(input logic [ADDR_WIDTH-1:0] addr, output logic [DATA_WIDTH-1:0] data);
        begin
            @(posedge clk);
            ARADDR  <= addr;
            ARVALID <= 1;
            RREADY  <= 1;

            wait (ARREADY);
            @(posedge clk);
            ARVALID <= 0;

            wait (RVALID);
            data = RDATA;
            @(posedge clk);
            RREADY <= 0;
        end
    endtask

endmodule
