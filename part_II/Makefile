# Makefile for Graph Algorithms Project
# Compiler
CXX = g++

# Compilation flags
CXXFLAGS = -std=c++11 -Wall -Wextra -O2

# Header files
HEADERS = Grafo.hpp

# Executables
TARGETS = strongly_connected_components_SCCs topological_sort kruskal_algorithm

# Default rule: compile all programs
all: $(TARGETS)

# Compilation of program 1 - Strongly Connected Components
strongly_connected_components_SCCs: strongly_connected_components_SCCs.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -o strongly_connected_components_SCCs strongly_connected_components_SCCs.cpp

# Compilation of program 2 - Topological Sort
topological_sort: topological_sort.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -o topological_sort topological_sort.cpp

# Compilation of program 3 - Minimum Spanning Tree (Kruskal)
kruskal_algorithm: kruskal_algorithm.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -o kruskal_algorithm kruskal_algorithm.cpp

# Clean compiled files
clean:
	rm -f $(TARGETS) *.o

# Phony targets
.PHONY: all clean test

# Quick test (requires test files)
test: all
	@echo "Testing Strongly Connected Components..."
	@if [ -f test_scc.net ]; then ./strongly_connected_components_SCCs test_scc.net; else echo "test_scc.net not found"; fi
	@echo ""
	@echo "Testing Topological Sort..."
	@if [ -f test_topo.net ]; then ./topological_sort test_topo.net; else echo "test_topo.net not found"; fi
	@echo ""
	@echo "Testing Kruskal Algorithm..."
	@if [ -f test_mst.net ]; then ./kruskal_algorithm test_mst.net; else echo "test_mst.net not found"; fi
	@echo ""
