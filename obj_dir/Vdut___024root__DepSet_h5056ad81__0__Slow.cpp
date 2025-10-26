// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdut.h for the primary calling header

#include "Vdut__pch.h"
#include "Vdut___024root.h"

VL_ATTR_COLD void Vdut___024root___eval_static(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_static\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__ACLK__0 = vlSelfRef.ACLK;
    vlSelfRef.__Vtrigprevexpr___TOP__dut__DOT__u_axi_fifo__DOT____Vcellinp__u_fifo__rst__0 
        = vlSelfRef.dut__DOT__u_axi_fifo__DOT____Vcellinp__u_fifo__rst;
}

VL_ATTR_COLD void Vdut___024root___eval_initial(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_initial\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vdut___024root___eval_final(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_final\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdut___024root___dump_triggers__stl(Vdut___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vdut___024root___eval_phase__stl(Vdut___024root* vlSelf);

VL_ATTR_COLD void Vdut___024root___eval_settle(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_settle\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vdut___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("rtl\\dut.v", 5, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vdut___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdut___024root___dump_triggers__stl(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___dump_triggers__stl\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vdut___024root___stl_sequent__TOP__0(Vdut___024root* vlSelf);

VL_ATTR_COLD void Vdut___024root___eval_stl(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_stl\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        Vdut___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void Vdut___024root___stl_sequent__TOP__0(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___stl_sequent__TOP__0\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.dut__DOT__u_axi_fifo__DOT____Vcellinp__u_fifo__rst 
        = (1U & (~ (IData)(vlSelfRef.ARESETn)));
    vlSelfRef.fifo_level = vlSelfRef.dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__count_internal;
}

VL_ATTR_COLD void Vdut___024root___eval_triggers__stl(Vdut___024root* vlSelf);

VL_ATTR_COLD bool Vdut___024root___eval_phase__stl(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___eval_phase__stl\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vdut___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        Vdut___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdut___024root___dump_triggers__ico(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___dump_triggers__ico\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdut___024root___dump_triggers__act(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___dump_triggers__act\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge ACLK)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge dut.u_axi_fifo.__Vcellinp__u_fifo__rst)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vdut___024root___dump_triggers__nba(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___dump_triggers__nba\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge ACLK)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge dut.u_axi_fifo.__Vcellinp__u_fifo__rst)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vdut___024root___ctor_var_reset(Vdut___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdut___024root___ctor_var_reset\n"); );
    Vdut__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->name());
    vlSelf->ACLK = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3034660589080906099ull);
    vlSelf->ARESETn = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11625642876178449192ull);
    vlSelf->AWADDR = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3704207311081907456ull);
    vlSelf->AWVALID = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11750918698781911943ull);
    vlSelf->AWREADY = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17297234574184235162ull);
    vlSelf->WDATA = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 13545846466767745629ull);
    vlSelf->WVALID = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9495255681580949789ull);
    vlSelf->WREADY = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17076114656213402080ull);
    vlSelf->BRESP = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 12793087776628502554ull);
    vlSelf->BVALID = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8367422369656964262ull);
    vlSelf->BREADY = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18149121645282540317ull);
    vlSelf->ARADDR = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17761954141230437835ull);
    vlSelf->ARVALID = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1896485211029909696ull);
    vlSelf->ARREADY = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11936612248788037190ull);
    vlSelf->RDATA = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4866321451055619796ull);
    vlSelf->RRESP = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 17082317525515500324ull);
    vlSelf->RVALID = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5829902753712117520ull);
    vlSelf->RREADY = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2085817933989443683ull);
    vlSelf->fifo_level = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 1491652487181845871ull);
    vlSelf->dut__DOT__u_axi_fifo__DOT__wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13262185513058160403ull);
    vlSelf->dut__DOT__u_axi_fifo__DOT__rd_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8509296912840861600ull);
    vlSelf->dut__DOT__u_axi_fifo__DOT__full = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17964093383653793762ull);
    vlSelf->dut__DOT__u_axi_fifo__DOT__empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7709960054401472859ull);
    vlSelf->dut__DOT__u_axi_fifo__DOT____Vcellinp__u_fifo__rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12485346923001305046ull);
    vlSelf->dut__DOT__u_axi_fifo__DOT__write_state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 9076743252231626837ull);
    vlSelf->dut__DOT__u_axi_fifo__DOT__read_state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11824774168778116079ull);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__mem[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 9087930251149039466ull);
    }
    vlSelf->dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__wr_ptr = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 3665851199147540953ull);
    vlSelf->dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__rd_ptr = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 4644214085673353138ull);
    vlSelf->dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__count_internal = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 15469880809382197096ull);
    vlSelf->dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__reset_sync = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17924395549929551250ull);
    vlSelf->dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__wr_en_d = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13949877421272301161ull);
    vlSelf->__Vdly__dut__DOT__u_axi_fifo__DOT__write_state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 18005638993339382348ull);
    vlSelf->__Vdly__dut__DOT__u_axi_fifo__DOT__read_state = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 17317070048999672391ull);
    vlSelf->__Vdly__dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__rd_ptr = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 16977637512780195212ull);
    vlSelf->__Vdly__dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__count_internal = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 4566126236360014340ull);
    vlSelf->__Vdly__dut__DOT__u_axi_fifo__DOT__full = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17762061342605309061ull);
    vlSelf->__Vdly__dut__DOT__u_axi_fifo__DOT__empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4668711152058247273ull);
    vlSelf->__VdlyVal__dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__mem__v0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 17894974753474901758ull);
    vlSelf->__VdlyDim0__dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__mem__v0 = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 10258260702988728610ull);
    vlSelf->__VdlySet__dut__DOT__u_axi_fifo__DOT__u_fifo__DOT__mem__v0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__ACLK__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17891880044439832025ull);
    vlSelf->__Vtrigprevexpr___TOP__dut__DOT__u_axi_fifo__DOT____Vcellinp__u_fifo__rst__0 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9324715605219447238ull);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
