CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

TARGETS = A1_2 A1_3 A1_4 A1_5

all: $(TARGETS)

A1_2: A1_2.cpp grafo.hpp
	$(CXX) $(CXXFLAGS) -o A1_2 A1_2.cpp

A1_3: A1_3.cpp grafo.hpp
	$(CXX) $(CXXFLAGS) -o A1_3 A1_3.cpp

A1_4: A1_4.cpp grafo.hpp
	$(CXX) $(CXXFLAGS) -o A1_4 A1_4.cpp

A1_5: A1_5.cpp grafo.hpp
	$(CXX) $(CXXFLAGS) -o A1_5 A1_5.cpp

clean:
	rm -f $(TARGETS)

test: all
	@echo "Testando com fln_pequena.net..."
	@echo "\n=== Teste Busca em Largura (A1_2) ==="
	./A1_2 fln_pequena.net 1
	@echo "\n=== Teste Ciclo Euleriano (A1_3) ==="
	./A1_3 fln_pequena.net
	@echo "\n=== Teste Dijkstra (A1_4) ==="
	./A1_4 fln_pequena.net 2
	@echo "\n=== Teste Floyd-Warshall (A1_5) ==="
	./A1_5 fln_pequena.net

.PHONY: all clean test
