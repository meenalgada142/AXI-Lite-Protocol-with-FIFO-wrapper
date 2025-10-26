#============================================================
# Makefile for Verilator-based AXI-Lite FIFO simulation
#============================================================

TOP = dut

CXXFLAGS = -std=c++17 \
			-Iobj_dir \
			-I/mingw64/share/verilator/include \
			-I/mingw64/share/verilator/include/vltstd \
			-I. \
			-Isim \
			-I./include \
			-Wall \
			-Wno-sign-compare

SRC = sim/tb_top.cpp sim/driver.cpp sim/monitor.cpp sim/coverage_tracker.cpp sim/sequence.cpp
OBJ = $(SRC:.cpp=.o)

VERILATOR_SRC = \
	/mingw64/share/verilator/include/verilated.cpp \
	/mingw64/share/verilator/include/verilated_threads.cpp \
	/mingw64/share/verilator/include/verilated_vcd_c.cpp

all: sim

# Verilate RTL with include path fix
obj_dir/V$(TOP).cpp: rtl/dut.v rtl/axi_lite_fifo_wrapper.sv rtl/fifo.sv
	verilator -Wall --trace --cc rtl/dut.v rtl/axi_lite_fifo_wrapper.sv rtl/fifo.sv \
		--exe sim/tb_top.cpp sim/driver.cpp sim/monitor.cpp sim/coverage_tracker.cpp sim/sequence.cpp \
		-CFLAGS "-I../include -std=c++17"
	make -C obj_dir -f V$(TOP).mk VERBOSE=1

# Compile C++ sources from sim/
sim/%.o: sim/%.cpp obj_dir/V$(TOP).cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Link simulation
sim: $(OBJ) obj_dir/V$(TOP)__ALL.a
	$(CXX) $(CXXFLAGS) -o run_sim $(OBJ) $(VERILATOR_SRC) obj_dir/V$(TOP)__ALL.a

# Clean
clean:
	rm -rf obj_dir sim.exe *.o sim/*.o

.PHONY: all clean sim
