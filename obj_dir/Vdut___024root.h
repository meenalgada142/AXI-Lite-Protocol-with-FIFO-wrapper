// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vdut.h for the primary calling header

#ifndef VERILATED_VDUT___024ROOT_H_
#define VERILATED_VDUT___024ROOT_H_  // guard

#include "verilated.h"


class Vdut__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vdut___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(ACLK,0,0);
    CData/*0:0*/ dut__DOT__u_axi_fifo__DOT____Vcellinp__u_fifo__rst;
    VL_IN8(ARESETn,0,0);
    VL_IN8(AWVALID,0,0);
    VL_OUT8(AWREADY,0,0);
    VL_IN8(WVALID,0,0);
    VL_OUT8(WREADY,0,0);
    VL_OUT8(BRESP,1,0);
    VL_OUT8(BVALID,0,0);
    VL_IN8(BREADY,0,0);
    VL_IN8(ARVALID,0,0);
    VL_OUT8(ARREADY,0,0);
    VL_OUT8(RRESP,1,0);
    VL_OUT8(RVALID,0,0);
    VL_IN8(RREADY,0,0);
    VL_OUT8(fifo_level,4,0);
    CData/*0:0*/ dut__DOT__u_axi_fifo__DOT__wr_en;
    CData/*0:0*/ dut__DOT__u_axi_fifo__DOT__rd_en;
    CData/*0:0*/ dut__DOT__u_axi_fifo__DOT__full;
    CData/*0:0*/ dut__DOT__u_axi_fifo__DOT__empty;
    CData/*1:0*/ dut__DOT__u_axi_fifo__DOT__write_state;
    CData/*1:0*/ dut__DOT__u_axi_fifo__DOT__read_state;
    CData/*3:0*/ dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__wr_ptr;
    CData/*3:0*/ dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__rd_ptr;
    CData/*4:0*/ dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__count_internal;
    CData/*0:0*/ dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__reset_sync;
    CData/*0:0*/ dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__wr_en_d;
    CData/*1:0*/ __Vdly__dut__DOT__u_axi_fifo__DOT__write_state;
    CData/*1:0*/ __Vdly__dut__DOT__u_axi_fifo__DOT__read_state;
    CData/*3:0*/ __Vdly__dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__rd_ptr;
    CData/*4:0*/ __Vdly__dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__count_internal;
    CData/*0:0*/ __Vdly__dut__DOT__u_axi_fifo__DOT__full;
    CData/*0:0*/ __Vdly__dut__DOT__u_axi_fifo__DOT__empty;
    CData/*7:0*/ __VdlyVal__dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__mem__v0;
    CData/*3:0*/ __VdlyDim0__dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__mem__v0;
    CData/*0:0*/ __VdlySet__dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__mem__v0;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__ACLK__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__dut__DOT__u_axi_fifo__DOT____Vcellinp__u_fifo__rst__0;
    CData/*0:0*/ __VactContinue;
    VL_IN(AWADDR,31,0);
    VL_IN(WDATA,31,0);
    VL_IN(ARADDR,31,0);
    VL_OUT(RDATA,31,0);
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*7:0*/, 16> dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__mem;
    VlUnpacked<CData/*0:0*/, 3> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vdut__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vdut___024root(Vdut__Syms* symsp, const char* v__name);
    ~Vdut___024root();
    VL_UNCOPYABLE(Vdut___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
