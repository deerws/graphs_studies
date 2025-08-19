# Graph Theory Projects 📊

A collection of graph theory algorithms and data structures implemented in C++.

## 🎯 Overview

This repository contains implementations of fundamental graph algorithms including search algorithms, shortest path algorithms, and cycle detection. All projects follow academic standards with optimized data structures and comprehensive documentation.

## 🚀 Projects

### A1 - Graph Fundamentals
- **Graph Representation**: Weighted undirected graph implementation with O(1) operations
- **Breadth-First Search (BFS)**: Level-order traversal and graph exploration
- **Eulerian Cycle Detection**: Hierholzer's algorithm for finding Eulerian cycles
- **Shortest Path Algorithms**: Dijkstra's algorithm for single-source shortest paths
- **All-Pairs Shortest Paths**: Floyd-Warshall algorithm implementation

## 🛠️ Technical Stack

- **Language**: C++17
- **Build System**: Makefile
- **Data Structures**: Hash maps, adjacency lists, priority queues
- **Algorithms**: Graph traversal, dynamic programming, greedy algorithms


## 🔧 Getting Started

### Prerequisites
- C++17 compatible compiler (GCC, Clang, or MSVC)
- Make (optional, for automated building)

### Compilation
```bash
# Clone the repository
git clone https://github.com/deerws/graphs_studies.git
cd part_I

# Compile all programs
make all

# Or compile individually
g++ -std=c++17 -Wall -Wextra -O2 -o A1_2 A1_2.cpp
```

## 📊 Input Format

Graph files follow the standard `.net` format:
```
*vertices n
1 "Vertex Label 1"
2 "Vertex Label 2"
...
*edges
1 2 weight
1 3 weight
...
```

## 🎓 Academic Context

These projects were developed as part of the **INE5413 - Graph Theory** course at UFSC Computer Science program. The implementations focus on:

- **Time Complexity Optimization**: O(1) operations where possible
- **Space Efficiency**: Optimized data structures for large graphs
- **Code Quality**: Clean, readable, and well-documented code
- **Academic Standards**: Following theoretical foundations precisely

## 🏆 Key Features

- ✅ **Optimized Performance**: Efficient algorithms with proper complexity analysis
- ✅ **Robust Implementation**: Handles edge cases and various graph types
- ✅ **Clean Code**: Well-structured and documented for educational purposes
- ✅ **Standard Compliance**: Follows academic algorithm specifications
- ✅ **Comprehensive Testing**: Validated against multiple test cases

## 📈 Algorithms Implemented

| Algorithm | Time Complexity | Space Complexity | Use Case |
|-----------|----------------|------------------|----------|
| BFS | O(V + E) | O(V) | Graph traversal, shortest unweighted paths |
| Eulerian Cycle | O(V + E) | O(E) | Cycle detection in graphs |
| Dijkstra | O((V + E) log V) | O(V) | Single-source shortest paths |
| Floyd-Warshall | O(V³) | O(V²) | All-pairs shortest paths |



## 📄 License

This project is developed for educational purposes as part of university coursework. Feel free to use it for learning and reference.

---

**Course**: INE5413 - Graph Theory  
**Institution**: Universidade Federal de Santa Catarina (UFSC)  
