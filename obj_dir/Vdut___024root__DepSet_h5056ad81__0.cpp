// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdut.h for the primary calling header

#include "Vdut__pch.h"
#include "Vdut___024root.h"

void Vdut___024root___ico_sequent__TOP__0(Vdut___024root* vlSelf);

void Vdut___024root___eval_ico(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_ico\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        Vdut___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vdut___024root___ico_sequent__TOP__0(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___ico_sequent__TOP__0\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.dut__DOT__u_axi_fifo__DOT____Vcellinp__u_fifo__rst 
        = (1U & (~ (IData)(vlSelfRef.ARESETn)));
}

void Vdut___024root___eval_triggers__ico(Vdut___024root* vlSelf);

bool Vdut___024root___eval_phase__ico(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_phase__ico\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vdut___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        Vdut___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vdut___024root___eval_act(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_act\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vdut___024root___nba_sequent__TOP__0(Vdut___024root* vlSelf);
void Vdut___024root___nba_sequent__TOP__1(Vdut___024root* vlSelf);
void Vdut___024root___nba_sequent__TOP__2(Vdut___024root* vlSelf);
void Vdut___024root___nba_sequent__TOP__3(Vdut___024root* vlSelf);

void Vdut___024root___eval_nba(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_nba\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vdut___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vdut___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vdut___024root___nba_sequent__TOP__2(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vdut___024root___nba_sequent__TOP__3(vlSelf);
        vlSelfRef.__Vm_traceActivity[2U] = 1U;
    }
}

VL_INLINE_OPT void Vdut___024root___nba_sequent__TOP__1(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___nba_sequent__TOP__1\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*3:0*/ __Vdly__dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__wr_ptr;
    __Vdly__dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__wr_ptr = 0;
    // Body
    __Vdly__dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__wr_ptr 
        = vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__wr_ptr;
    vlSelfRef.__Vdly__dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__rd_ptr 
        = vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__rd_ptr;
    vlSelfRef.__Vdly__dut__DOT__u_axi_fifo__DOT__full 
        = vlSelfRef.dut__DOT__u_axi_fifo__DOT__full;
    vlSelfRef.__Vdly__dut__DOT__u_axi_fifo__DOT__empty 
        = vlSelfRef.dut__DOT__u_axi_fifo__DOT__empty;
    vlSelfRef.__VdlySet__dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__mem__v0 = 0U;
    vlSelfRef.__Vdly__dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__count_internal 
        = vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__count_internal;
    if (vlSelfRef.dut__DOT__u_axi_fifo__DOT____Vcellinp__u_fifo__rst) {
        __Vdly__dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__wr_ptr = 0U;
        vlSelfRef.__Vdly__dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__rd_ptr = 0U;
        vlSelfRef.__Vdly__dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__count_internal = 0U;
        vlSelfRef.__Vdly__dut__DOT__u_axi_fifo__DOT__full = 0U;
        vlSelfRef.__Vdly__dut__DOT__u_axi_fifo__DOT__empty = 1U;
        vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__reset_sync = 1U;
    } else {
        if (((IData)(vlSelfRef.dut__DOT__u_axi_fifo__DOT__wr_en) 
             & (~ (IData)(vlSelfRef.dut__DOT__u_axi_fifo__DOT__full)))) {
            vlSelfRef.__Vdly__dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__count_internal 
                = (0x1fU & ((IData)(1U) + (IData)(vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__count_internal)));
            vlSelfRef.__VdlyVal__dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__mem__v0 
                = (0xffU & vlSelfRef.WDATA);
            vlSelfRef.__VdlyDim0__dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__mem__v0 
                = vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__wr_ptr;
            vlSelfRef.__VdlySet__dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__mem__v0 = 1U;
            __Vdly__dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__wr_ptr 
                = (0xfU & ((IData)(1U) + (IData)(vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__wr_ptr)));
        }
        if (((IData)(vlSelfRef.dut__DOT__u_axi_fifo__DOT__rd_en) 
             & (~ (IData)(vlSelfRef.dut__DOT__u_axi_fifo__DOT__empty)))) {
            vlSelfRef.__Vdly__dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__rd_ptr 
                = (0xfU & ((IData)(1U) + (IData)(vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__rd_ptr)));
            vlSelfRef.__Vdly__dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__count_internal 
                = (0x1fU & ((IData)(vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__count_internal) 
                            - (IData)(1U)));
        }
        vlSelfRef.__Vdly__dut__DOT__u_axi_fifo__DOT__full 
            = (0x10U == (IData)(vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__count_internal));
        vlSelfRef.__Vdly__dut__DOT__u_axi_fifo__DOT__empty 
            = (0U == (IData)(vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__count_internal));
        vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__reset_sync = 0U;
    }
    vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__wr_ptr 
        = __Vdly__dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__wr_ptr;
}

VL_INLINE_OPT void Vdut___024root___nba_sequent__TOP__2(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___nba_sequent__TOP__2\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.ARESETn) {
        vlSelfRef.dut__DOT__u_axi_fifo__DOT__rd_en = 0U;
        if ((0U == (IData)(vlSelfRef.dut__DOT__u_axi_fifo__DOT__read_state))) {
            if (vlSelfRef.ARVALID) {
                vlSelfRef.ARREADY = 1U;
                if ((0x10U == (0xffU & vlSelfRef.ARADDR))) {
                    if (vlSelfRef.dut__DOT__u_axi_fifo__DOT__empty) {
                        vlSelfRef.RDATA = 0xdeadbeefU;
                        vlSelfRef.RRESP = 2U;
                    } else {
                        vlSelfRef.dut__DOT__u_axi_fifo__DOT__rd_en = 1U;
                        vlSelfRef.RDATA = vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__mem
                            [vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__rd_ptr];
                        vlSelfRef.RRESP = 0U;
                    }
                } else if ((0x20U == (0xffU & vlSelfRef.ARADDR))) {
                    vlSelfRef.RDATA = (((IData)(vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__count_internal) 
                                        << 2U) | (((IData)(vlSelfRef.dut__DOT__u_axi_fifo__DOT__full) 
                                                   << 1U) 
                                                  | (IData)(vlSelfRef.dut__DOT__u_axi_fifo__DOT__empty)));
                    vlSelfRef.RRESP = 0U;
                } else if ((0x80U == (0xffU & vlSelfRef.ARADDR))) {
                    vlSelfRef.RDATA = vlSelfRef.fifo_level;
                    vlSelfRef.RRESP = 0U;
                } else {
                    vlSelfRef.RDATA = 0xbad0bad0U;
                    vlSelfRef.RRESP = 3U;
                }
                vlSelfRef.__Vdly__dut__DOT__u_axi_fifo__DOT__read_state = 1U;
            }
        } else if ((1U == (IData)(vlSelfRef.dut__DOT__u_axi_fifo__DOT__read_state))) {
            vlSelfRef.ARREADY = 0U;
            vlSelfRef.RVALID = 1U;
            if (vlSelfRef.RREADY) {
                vlSelfRef.RVALID = 0U;
                vlSelfRef.__Vdly__dut__DOT__u_axi_fifo__DOT__read_state = 0U;
            }
        } else {
            vlSelfRef.ARREADY = 0U;
            vlSelfRef.RVALID = 0U;
            vlSelfRef.RDATA = 0xbad0bad0U;
            vlSelfRef.RRESP = 3U;
            vlSelfRef.dut__DOT__u_axi_fifo__DOT__rd_en = 0U;
            vlSelfRef.__Vdly__dut__DOT__u_axi_fifo__DOT__read_state = 0U;
        }
        vlSelfRef.dut__DOT__u_axi_fifo__DOT__wr_en = 0U;
        if ((0U == (IData)(vlSelfRef.dut__DOT__u_axi_fifo__DOT__write_state))) {
            vlSelfRef.AWREADY = 1U;
            vlSelfRef.WREADY = 1U;
            if (((IData)(vlSelfRef.AWVALID) & (IData)(vlSelfRef.WVALID))) {
                if (((0U == (0xfU & vlSelfRef.AWADDR)) 
                     & (~ (IData)(vlSelfRef.dut__DOT__u_axi_fifo__DOT__full)))) {
                    vlSelfRef.dut__DOT__u_axi_fifo__DOT__wr_en = 1U;
                    vlSelfRef.BRESP = 0U;
                } else {
                    vlSelfRef.BRESP = 2U;
                }
                vlSelfRef.__Vdly__dut__DOT__u_axi_fifo__DOT__write_state = 1U;
            }
        } else if ((1U == (IData)(vlSelfRef.dut__DOT__u_axi_fifo__DOT__write_state))) {
            vlSelfRef.AWREADY = 0U;
            vlSelfRef.WREADY = 0U;
            vlSelfRef.BVALID = 1U;
            if (vlSelfRef.BREADY) {
                vlSelfRef.BVALID = 0U;
                vlSelfRef.__Vdly__dut__DOT__u_axi_fifo__DOT__write_state = 0U;
            }
        } else {
            vlSelfRef.AWREADY = 0U;
            vlSelfRef.WREADY = 0U;
            vlSelfRef.BVALID = 0U;
            vlSelfRef.BRESP = 2U;
            vlSelfRef.dut__DOT__u_axi_fifo__DOT__wr_en = 0U;
            vlSelfRef.__Vdly__dut__DOT__u_axi_fifo__DOT__write_state = 0U;
        }
    } else {
        vlSelfRef.__Vdly__dut__DOT__u_axi_fifo__DOT__read_state = 0U;
        vlSelfRef.ARREADY = 0U;
        vlSelfRef.RVALID = 0U;
        vlSelfRef.RDATA = 0U;
        vlSelfRef.RRESP = 0U;
        vlSelfRef.dut__DOT__u_axi_fifo__DOT__rd_en = 0U;
        vlSelfRef.__Vdly__dut__DOT__u_axi_fifo__DOT__write_state = 0U;
        vlSelfRef.AWREADY = 0U;
        vlSelfRef.WREADY = 0U;
        vlSelfRef.BVALID = 0U;
        vlSelfRef.BRESP = 0U;
        vlSelfRef.dut__DOT__u_axi_fifo__DOT__wr_en = 0U;
    }
    vlSelfRef.dut__DOT__u_axi_fifo__DOT__read_state 
        = vlSelfRef.__Vdly__dut__DOT__u_axi_fifo__DOT__read_state;
    vlSelfRef.dut__DOT__u_axi_fifo__DOT__write_state 
        = vlSelfRef.__Vdly__dut__DOT__u_axi_fifo__DOT__write_state;
}

VL_INLINE_OPT void Vdut___024root___nba_sequent__TOP__3(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___nba_sequent__TOP__3\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.dut__DOT__u_axi_fifo__DOT__empty = vlSelfRef.__Vdly__dut__DOT__u_axi_fifo__DOT__empty;
    vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__rd_ptr 
        = vlSelfRef.__Vdly__dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__rd_ptr;
    if (vlSelfRef.__VdlySet__dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__mem__v0) {
        vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__mem[vlSelfRef.__VdlyDim0__dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__mem__v0] 
            = vlSelfRef.__VdlyVal__dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__mem__v0;
    }
    vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__count_internal 
        = vlSelfRef.__Vdly__dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__count_internal;
    vlSelfRef.dut__DOT__u_axi_fifo__DOT__full = vlSelfRef.__Vdly__dut__DOT__u_axi_fifo__DOT__full;
    vlSelfRef.fifo_level = vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__count_internal;
}

void Vdut___024root___eval_triggers__act(Vdut___024root* vlSelf);

bool Vdut___024root___eval_phase__act(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_phase__act\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vdut___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vdut___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vdut___024root___eval_phase__nba(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_phase__nba\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vdut___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdut___024root___dump_triggers__ico(Vdut___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vdut___024root___dump_triggers__nba(Vdut___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vdut___024root___dump_triggers__act(Vdut___024root* vlSelf);
#endif  // VL_DEBUG

void Vdut___024root___eval(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY(((0x64U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vdut___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("rtl\\dut.v", 5, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vdut___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vdut___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("rtl\\dut.v", 5, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vdut___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("rtl\\dut.v", 5, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vdut___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vdut___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vdut___024root___eval_debug_assertions(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_debug_assertions\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.ACLK & 0xfeU)))) {
        Verilated::overWidthError("ACLK");}
    if (VL_UNLIKELY(((vlSelfRef.ARESETn & 0xfeU)))) {
        Verilated::overWidthError("ARESETn");}
    if (VL_UNLIKELY(((vlSelfRef.AWVALID & 0xfeU)))) {
        Verilated::overWidthError("AWVALID");}
    if (VL_UNLIKELY(((vlSelfRef.WVALID & 0xfeU)))) {
        Verilated::overWidthError("WVALID");}
    if (VL_UNLIKELY(((vlSelfRef.BREADY & 0xfeU)))) {
        Verilated::overWidthError("BREADY");}
    if (VL_UNLIKELY(((vlSelfRef.ARVALID & 0xfeU)))) {
        Verilated::overWidthError("ARVALID");}
    if (VL_UNLIKELY(((vlSelfRef.RREADY & 0xfeU)))) {
        Verilated::overWidthError("RREADY");}
}
#endif  // VL_DEBUG
