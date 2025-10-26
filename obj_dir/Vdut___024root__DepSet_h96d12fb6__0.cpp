// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdut.h for the primary calling header

#include "Vdut__pch.h"
#include "Vdut__Syms.h"
#include "Vdut___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdut___024root___dump_triggers__ico(Vdut___024root* vlSelf);
#endif  // VL_DEBUG

void Vdut___024root___eval_triggers__ico(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_triggers__ico\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered.setBit(0U, (IData)(vlSelfRef.__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vdut___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdut___024root___dump_triggers__act(Vdut___024root* vlSelf);
#endif  // VL_DEBUG

void Vdut___024root___eval_triggers__act(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_triggers__act\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.setBit(0U, ((IData)(vlSelfRef.ACLK) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__ACLK__0))));
    vlSelfRef.__VactTriggered.setBit(1U, ((IData)(vlSelfRef.dut__DOT__u_axi_fifo__DOT____Vcellinp__u_fifo__rst) 
                                          & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__dut__DOT__u_axi_fifo__DOT____Vcellinp__u_fifo__rst__0))));
    vlSelfRef.__Vtrigprevexpr___TOP__ACLK__0 = vlSelfRef.ACLK;
    vlSelfRef.__Vtrigprevexpr___TOP__dut__DOT__u_axi_fifo__DOT____Vcellinp__u_fifo__rst__0 
        = vlSelfRef.dut__DOT__u_axi_fifo__DOT____Vcellinp__u_fifo__rst;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vdut___024root___dump_triggers__act(vlSelf);
    }
#endif
}

VL_INLINE_OPT void Vdut___024root___nba_sequent__TOP__0(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___nba_sequent__TOP__0\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ (IData)(vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__reset_sync)))) {
        if (VL_UNLIKELY(((0x10U < (IData)(vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__count_internal))))) {
            VL_WRITEF_NX("[%0t] %%Error: fifo.sv:54: Assertion failed in %Ndut.u_axi_fifo.u_fifo: FIFO count exceeded DEPTH\n",0,
                         64,VL_TIME_UNITED_Q(1),-12,
                         vlSymsp->name());
            VL_STOP_MT("rtl\\fifo.sv", 54, "");
        }
    }
    vlSelfRef.__Vdly__dut__DOT__u_axi_fifo__DOT__write_state 
        = vlSelfRef.dut__DOT__u_axi_fifo__DOT__write_state;
    vlSelfRef.__Vdly__dut__DOT__u_axi_fifo__DOT__read_state 
        = vlSelfRef.dut__DOT__u_axi_fifo__DOT__read_state;
    if ((1U & (~ (IData)(vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__reset_sync)))) {
        if (VL_UNLIKELY((((IData)(vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__wr_en_d) 
                          & (IData)(vlSelfRef.dut__DOT__u_axi_fifo__DOT__full))))) {
            VL_WRITEF_NX("[%0t] %%Error: fifo.sv:36: Assertion failed in %Ndut.u_axi_fifo.u_fifo: FIFO became full in the cycle after write\n",0,
                         64,VL_TIME_UNITED_Q(1),-12,
                         vlSymsp->name());
            VL_STOP_MT("rtl\\fifo.sv", 36, "");
        }
    }
    if ((1U & (~ (IData)(vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__reset_sync)))) {
        if (VL_UNLIKELY((((IData)(vlSelfRef.dut__DOT__u_axi_fifo__DOT__rd_en) 
                          & (0U == (IData)(vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__count_internal)))))) {
            VL_WRITEF_NX("[%0t] %%Error: fifo.sv:45: Assertion failed in %Ndut.u_axi_fifo.u_fifo: FIFO underflow: read attempted when empty\n",0,
                         64,VL_TIME_UNITED_Q(1),-12,
                         vlSymsp->name());
            VL_STOP_MT("rtl\\fifo.sv", 45, "");
        }
    }
    vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__wr_en_d 
        = vlSelfRef.dut__DOT__u_axi_fifo__DOT__wr_en;
}
