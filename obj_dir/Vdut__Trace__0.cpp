// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vdut__Syms.h"


void Vdut___024root__trace_chg_0_sub_0(Vdut___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vdut___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_chg_0\n"); );
    // Init
    Vdut___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdut___024root*>(voidSelf);
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vdut___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vdut___024root__trace_chg_0_sub_0(Vdut___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_chg_0_sub_0\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgBit(oldp+0,(vlSelfRef.dut__DOT__u_axi_fifo__DOT__wr_en));
        bufp->chgBit(oldp+1,(vlSelfRef.dut__DOT__u_axi_fifo__DOT__rd_en));
        bufp->chgCData(oldp+2,(vlSelfRef.dut__DOT__u_axi_fifo__DOT__write_state),2);
        bufp->chgCData(oldp+3,(vlSelfRef.dut__DOT__u_axi_fifo__DOT__read_state),2);
    }
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[2U]))) {
        bufp->chgCData(oldp+4,(vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__mem
                               [vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__rd_ptr]),8);
        bufp->chgBit(oldp+5,(vlSelfRef.dut__DOT__u_axi_fifo__DOT__full));
        bufp->chgBit(oldp+6,(vlSelfRef.dut__DOT__u_axi_fifo__DOT__empty));
        bufp->chgCData(oldp+7,(vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__count_internal),5);
        bufp->chgCData(oldp+8,(vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__mem[0]),8);
        bufp->chgCData(oldp+9,(vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__mem[1]),8);
        bufp->chgCData(oldp+10,(vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__mem[2]),8);
        bufp->chgCData(oldp+11,(vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__mem[3]),8);
        bufp->chgCData(oldp+12,(vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__mem[4]),8);
        bufp->chgCData(oldp+13,(vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__mem[5]),8);
        bufp->chgCData(oldp+14,(vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__mem[6]),8);
        bufp->chgCData(oldp+15,(vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__mem[7]),8);
        bufp->chgCData(oldp+16,(vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__mem[8]),8);
        bufp->chgCData(oldp+17,(vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__mem[9]),8);
        bufp->chgCData(oldp+18,(vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__mem[10]),8);
        bufp->chgCData(oldp+19,(vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__mem[11]),8);
        bufp->chgCData(oldp+20,(vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__mem[12]),8);
        bufp->chgCData(oldp+21,(vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__mem[13]),8);
        bufp->chgCData(oldp+22,(vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__mem[14]),8);
        bufp->chgCData(oldp+23,(vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__mem[15]),8);
        bufp->chgCData(oldp+24,(vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__rd_ptr),4);
    }
    bufp->chgBit(oldp+25,(vlSelfRef.ACLK));
    bufp->chgBit(oldp+26,(vlSelfRef.ARESETn));
    bufp->chgIData(oldp+27,(vlSelfRef.AWADDR),32);
    bufp->chgBit(oldp+28,(vlSelfRef.AWVALID));
    bufp->chgBit(oldp+29,(vlSelfRef.AWREADY));
    bufp->chgIData(oldp+30,(vlSelfRef.WDATA),32);
    bufp->chgBit(oldp+31,(vlSelfRef.WVALID));
    bufp->chgBit(oldp+32,(vlSelfRef.WREADY));
    bufp->chgCData(oldp+33,(vlSelfRef.BRESP),2);
    bufp->chgBit(oldp+34,(vlSelfRef.BVALID));
    bufp->chgBit(oldp+35,(vlSelfRef.BREADY));
    bufp->chgIData(oldp+36,(vlSelfRef.ARADDR),32);
    bufp->chgBit(oldp+37,(vlSelfRef.ARVALID));
    bufp->chgBit(oldp+38,(vlSelfRef.ARREADY));
    bufp->chgIData(oldp+39,(vlSelfRef.RDATA),32);
    bufp->chgCData(oldp+40,(vlSelfRef.RRESP),2);
    bufp->chgBit(oldp+41,(vlSelfRef.RVALID));
    bufp->chgBit(oldp+42,(vlSelfRef.RREADY));
    bufp->chgCData(oldp+43,(vlSelfRef.fifo_level),5);
    bufp->chgBit(oldp+44,((0U != (vlSelfRef.AWADDR 
                                  >> 4U))));
    bufp->chgBit(oldp+45,((0U != (vlSelfRef.WDATA >> 8U))));
    bufp->chgBit(oldp+46,((0U != (vlSelfRef.ARADDR 
                                  >> 4U))));
    bufp->chgBit(oldp+47,(vlSelfRef.dut__DOT__u_axi_fifo__DOT____Vcellinp__u_fifo__rst));
    bufp->chgCData(oldp+48,((0xffU & vlSelfRef.WDATA)),8);
    bufp->chgCData(oldp+49,(vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__wr_ptr),4);
    bufp->chgBit(oldp+50,(vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__reset_sync));
    bufp->chgBit(oldp+51,(vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__wr_en_d));
}

void Vdut___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root__trace_cleanup\n"); );
    // Init
    Vdut___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdut___024root*>(voidSelf);
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
