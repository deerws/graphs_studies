# Graph Theory Projects 📊

A collection of graph theory algorithms and data structures implemented in C++ for academic coursework at Universidade Federal de Santa Catarina (UFSC).

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

## 📁 Project Structure

```
├── A1_Graph_Fundamentals/
│   ├── grafo.hpp              # Graph class implementation
│   ├── A1_2.cpp               # BFS algorithm
│   ├── A1_3.cpp               # Eulerian cycle detection
│   ├── A1_4.cpp               # Dijkstra's algorithm
│   ├── A1_5.cpp               # Floyd-Warshall algorithm
│   ├── Makefile               # Build configuration
│   └── test_files/            # Sample graph data
└── README.md
```

## 🔧 Getting Started

### Prerequisites
- C++17 compatible compiler (GCC, Clang, or MSVC)
- Make (optional, for automated building)

### Compilation
```bash
# Clone the repository
git clone https://github.com/yourusername/graph-theory-projects.git
cd graph-theory-projects/A1_Graph_Fundamentals

# Compile all programs
make all

# Or compile individually
g++ -std=c++17 -Wall -Wextra -O2 -o A1_2 A1_2.cpp
```

### Usage
```bash
# Run BFS from vertex 1
./A1_2 graph_file.net 1

# Check for Eulerian cycle
./A1_3 graph_file.net

# Find shortest paths from vertex 2
./A1_4 graph_file.net 2

# Compute all-pairs shortest paths
./A1_5 graph_file.net
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

## 🤝 Contributing

This is an academic project, but suggestions and improvements are welcome! Please feel free to:
- Report bugs or issues
- Suggest optimizations
- Provide additional test cases
- Improve documentation

## 📄 License

This project is developed for educational purposes as part of university coursework. Feel free to use it for learning and reference.

---

**Course**: INE5413 - Graph Theory  
**Institution**: Universidade Federal de Santa Catarina (UFSC)  
**Program**: Computer Science