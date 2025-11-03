# 🔄 Advanced Graph Algorithms Implementation

[![C++](https://img.shields.io/badge/C++-11%2B-blue.svg)](https://isocpp.org/)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![Algorithms](https://img.shields.io/badge/Algorithms-3-orange.svg)]()

A comprehensive implementation of three fundamental graph algorithms with applications in network optimization, resource allocation, and scheduling problems.

---

## 🎯 Overview

This project explores advanced graph theory through efficient C++ implementations of algorithms that solve critical problems in computer science and operations research:

- **Maximum Flow** — Optimizing network capacity
- **Maximum Matching** — Bipartite graph optimization  
- **Graph Coloring** — Resource allocation without conflicts

Each algorithm is implemented with careful attention to data structure selection, computational complexity, and practical performance.

---

## 📚 Implemented Algorithms

### 1️⃣ Edmonds-Karp Algorithm (Maximum Flow)

**Problem**: Given a directed weighted graph with edge capacities, find the maximum flow from a source vertex to a sink vertex.

**Applications**:
- Network bandwidth optimization
- Traffic routing in transportation systems
- Supply chain management
- Image segmentation

**Complexity**: 
- Time: O(V·E²)
- Space: O(V²)

**Key Features**:
- BFS-based path finding for shortest augmenting paths
- Residual capacity graph maintenance
- Guarantees optimal solution

```cpp
// Usage example
Grafo g = Grafo::lerArquivo("network.net");
double maxFlow = g.edmondsKarp(source, sink);
```

---

### 2️⃣ Hopcroft-Karp Algorithm (Maximum Matching)

**Problem**: Find the largest possible matching in a bipartite graph (maximum set of edges with no common vertices).

**Applications**:
- Job assignment problems
- Dating/matching services
- Resource allocation
- Task scheduling

**Complexity**: 
- Time: O(√V·E)
- Space: O(V + E)

**Key Features**:
- Phase-based approach (BFS + multiple DFS)
- Processes multiple augmenting paths simultaneously
- Significantly faster than naive augmenting path methods

```cpp
// Usage example
Grafo g = Grafo::lerArquivo("bipartite.net");
auto result = g.hopcroftKarp(n1);
int matching = result.first;
vector<pair<int,int>> edges = result.second;
```

---

### 3️⃣ Lawler's Algorithm (Graph Coloring)

**Problem**: Assign colors to vertices such that no two adjacent vertices share the same color, using the minimum number of colors possible.

**Applications**:
- Register allocation in compilers
- Frequency assignment in wireless networks
- Scheduling with conflict constraints
- Map coloring

**Complexity**: 
- Time: O(V log V + V·E) for greedy heuristic
- Space: O(V + E)

**Key Features**:
- Welsh-Powell greedy strategy
- Degree-based vertex ordering
- Near-optimal solutions for most practical cases

```cpp
// Usage example
Grafo g = Grafo::lerArquivo("graph.net");
auto result = g.lawler();
int chromaticNumber = result.first;
vector<int> colors = result.second;
```

---

## 🛠️ Technical Architecture

### Data Structures

#### Edge Representation
```cpp
struct Aresta {
    int destino;
    double peso;
    double fluxo;
};
```

#### Graph Class
- **Adjacency List**: `vector<vector<Aresta>>`
- Supports directed/undirected and weighted/unweighted graphs
- Built-in file parsing for Pajek .net format
- Modular algorithm implementations

### Design Principles

1. **Separation of Concerns**: Graph structure separate from algorithms
2. **Reusability**: Single graph class supports multiple algorithms
3. **Efficiency**: Data structures chosen for optimal algorithm performance
4. **Clarity**: Clean, documented code with meaningful variable names

---

## 🚀 Getting Started

### Prerequisites

- C++ compiler with C++11 support or higher
- Make (optional, for build automation)

### Compilation

#### Using Make
```bash
make all
```

#### Manual Compilation
```bash
g++ -std=c++11 -O2 src/A3_1.cpp -o A3_1
g++ -std=c++11 -O2 src/A3_2.cpp -o A3_2
g++ -std=c++11 -O2 src/A3_3.cpp -o A3_3
```

### Running the Programs

#### Maximum Flow (Edmonds-Karp)
```bash
./A3_1 data/network.net 1 6
# Arguments: <graph_file> <source_vertex> <sink_vertex>
# Output: Maximum flow value
```

#### Maximum Matching (Hopcroft-Karp)
```bash
./A3_2 data/bipartite.net
# Arguments: <graph_file>
# Output: Matching size and edge list
```

#### Graph Coloring (Lawler)
```bash
./A3_3 data/graph.net
# Arguments: <graph_file>
# Output: Chromatic number and vertex colors
```

---

## 📄 Input Format

All programs read graphs in Pajek .net format:

```
*vertices n
1 label_1
2 label_2
...
n label_n
*edges        (or *arcs for directed graphs)
u v weight
...
```

**Example** (Flow Network):
```
*vertices 6
1 Source
2 A
3 B
4 C
5 D
6 Sink
*arcs
1 2 10
1 3 10
2 4 4
2 5 8
3 4 9
4 6 10
5 6 10
```

---

## 📊 Performance Characteristics

| Algorithm | Best Case | Average Case | Worst Case | Space |
|-----------|-----------|--------------|------------|-------|
| Edmonds-Karp | O(VE) | O(VE²) | O(VE²) | O(V²) |
| Hopcroft-Karp | O(E) | O(√V·E) | O(√V·E) | O(V+E) |
| Lawler (Greedy) | O(V+E) | O(V log V + VE) | O(VE) | O(V+E) |

---

## 🔬 Algorithm Insights

### Why Edmonds-Karp?
- **BFS guarantees** shortest augmenting paths
- **Polynomial bound** on iterations (unlike Ford-Fulkerson)
- **Practical efficiency** for most real-world networks

### Why Hopcroft-Karp?
- **Phase-based approach** processes multiple paths per iteration
- **√V speedup** over naive augmenting path methods
- **Optimal for bipartite** matching problems

### Why Welsh-Powell for Coloring?
- **Greedy heuristic** provides good approximations
- **NP-complete problem** — exact solution impractical for large graphs
- **Degree-based ordering** empirically effective

---

## 📚 References

### Papers and Books
- Edmonds, J., & Karp, R. M. (1972). *Theoretical improvements in algorithmic efficiency for network flow problems*
- Hopcroft, J. E., & Karp, R. M. (1973). *An n^5/2 algorithm for maximum matchings in bipartite graphs*
- Lawler, E. L. (1976). *A note on the complexity of the chromatic number problem*
- Cormen, T. H., et al. (2009). *Introduction to Algorithms* (3rd ed.)

### Related Work
- NetworkX (Python) — Graph algorithms library
- Boost Graph Library (C++) — Comprehensive graph toolkit
- LEMON (C++) — Library for Efficient Modeling and Optimization in Networks

---

## 📝 License

This project is licensed under the MIT License - see [LICENSE](LICENSE) for details.

---

## 👤 Author

**André Pinheiro Paes**

This implementation was developed as part of exploring fundamental algorithms in computer science, with a focus on network optimization and combinatorial problems.

---


**Built with curiosity and C++** 🔍💻
