CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2

all: bfs dijkstra euler fw

bfs: breadth-first_search.cpp
	$(CXX) $(CXXFLAGS) breadth-first_search.cpp -o bfs

dijkstra: dijkstra_algorithm.cpp
	$(CXX) $(CXXFLAGS) dijkstra_algorithm.cpp -o dijkstra

euler: eulerian_cycle.cpp
	$(CXX) $(CXXFLAGS) eulerian_cycle.cpp -o euler

fw: floyd-warshall_algorithm.cpp
	$(CXX) $(CXXFLAGS) floyd-warshall_algorithm.cpp -o fw

clean:
	rm -f bfs dijkstra euler fw

