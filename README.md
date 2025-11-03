# 📊 Graph Algorithms Collection

[![C++](https://img.shields.io/badge/C++-11%2B-blue.svg)](https://isocpp.org/)
[![Algorithms](https://img.shields.io/badge/Algorithms-11-orange.svg)]()
[![License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)

A comprehensive collection of fundamental and advanced graph algorithms implemented in C++, exploring classical problems in graph theory, network optimization, and combinatorial algorithms.

---

## 🎯 Overview

This repository contains three progressive explorations of graph algorithms, from basic traversals to advanced optimization techniques. Each part builds upon the previous one, demonstrating the power and versatility of graph data structures.

**What's Inside:**
- **11 different algorithms** covering traversal, optimization, flow, and matching
- **Modular C++ library** with reusable components
- **Detailed documentation** and complexity analysis
- **Real-world applications** explained for each algorithm

---

## 🗂️ Parts Overview

### 📘 Part I: Foundational Graph Algorithms

**Focus**: Core graph operations, traversals, and shortest paths

**Algorithms Implemented**:
- ✅ **Graph Representation** — Adjacency list with O(1) operations
- ✅ **Breadth-First Search (BFS)** — Level-order traversal
- ✅ **Eulerian Cycle Detection** — Finding Eulerian paths
- ✅ **Dijkstra's Algorithm** — Single-source shortest paths (non-negative weights)
- ✅ **Bellman-Ford Algorithm** — Shortest paths with negative weights
- ✅ **Floyd-Warshall Algorithm** — All-pairs shortest paths

**Applications**: Network routing, social network analysis, GPS navigation

➡️ [**Explore Part I**](part_I/)

---

### 📗 Part II: Intermediate Optimization Algorithms

**Focus**: Graph decomposition, topological structures, and minimum spanning trees

**Algorithms Implemented**:
- ✅ **Kosaraju's Algorithm** — Strongly connected components
- ✅ **Topological Sorting** — DAG ordering with cycle detection
- ✅ **Kruskal's Algorithm** — Minimum spanning tree with Union-Find

**Applications**: Task scheduling, dependency resolution, network design

➡️ [**Explore Part II**](part_II/)

---

### 📙 Part III: Advanced Flow and Matching Algorithms

**Focus**: Network flows, bipartite matching, and graph coloring

**Algorithms Implemented**:
- ✅ **Edmonds-Karp Algorithm** — Maximum flow in networks
- ✅ **Hopcroft-Karp Algorithm** — Maximum bipartite matching
- ✅ **Lawler's Algorithm** — Graph coloring (Welsh-Powell heuristic)

**Applications**: Resource allocation, job assignment, frequency planning

➡️ [**Explore Part III**](part_III/)

---

## 📊 Algorithm Complexity Summary

| Algorithm | Time Complexity | Space | Part |
|-----------|----------------|-------|------|
| BFS | O(V + E) | O(V) | I |
| Dijkstra | O((V + E) log V) | O(V) | I |
| Bellman-Ford | O(V·E) | O(V) | I |
| Floyd-Warshall | O(V³) | O(V²) | I |
| Kosaraju (SCC) | O(V + E) | O(V + E) | II |
| Topological Sort | O(V + E) | O(V) | II |
| Kruskal | O(E log E) | O(V + E) | II |
| Edmonds-Karp | O(V·E²) | O(V²) | III |
| Hopcroft-Karp | O(√V·E) | O(V + E) | III |
| Welsh-Powell | O(V log V + V·E) | O(V + E) | III |

---

## 🎓 Learning Path

**Recommended progression** for understanding graph algorithms:

1. **Start with Part I** — Learn fundamental concepts
   - Graph representation choices
   - Traversal strategies (BFS/DFS)
   - Shortest path problems

2. **Continue to Part II** — Understand graph structures
   - Decomposition techniques
   - Topological properties
   - Optimization on trees

3. **Master Part III** — Tackle advanced problems
   - Network flow theory
   - Matching problems
   - NP-hard approximations

---

## 🛠️ Key Features

### Modular Design
- **Reusable library** across all parts
- **Clean separation** of algorithms and data structures
- **Easy to extend** with new algorithms

### Educational Focus
- **Detailed comments** in code
- **Complexity analysis** for each algorithm
- **Real-world applications** explained

### Production Quality
- **Efficient implementations** following best practices
- **Memory-conscious** data structure choices
- **Well-tested** with multiple graph instances

---

## 📖 Documentation

Each part contains:
- **Detailed README** with algorithm explanations
- **Technical report** (Portuguese) with complexity analysis
- **Usage examples** and sample inputs
- **API reference** for the graph library

---

## 🔬 Applications by Domain

### Network Engineering
- Shortest path routing (Dijkstra, Bellman-Ford)
- Network flow optimization (Edmonds-Karp)
- Spanning tree protocols (Kruskal)

### Computer Science
- Task scheduling (Topological Sort)
- Register allocation (Graph Coloring)
- Dead code elimination (SCC)

### Operations Research
- Resource allocation (Matching)
- Transportation problems (Flow)
- Network design (MST)

---

## 🤝 Contributing

This is a personal exploration of graph algorithms. However, improvements are welcome:

1. Fork the repository
2. Create a feature branch
3. Implement your enhancement
4. Submit a pull request

Please maintain code quality and include documentation.

---

## 📚 References

### Textbooks
- Cormen, T. H., et al. (2009). *Introduction to Algorithms* (3rd ed.)
- Sedgewick, R., & Wayne, K. (2011). *Algorithms* (4th ed.)
- West, D. B. (2001). *Introduction to Graph Theory* (2nd ed.)

### Papers
- Dijkstra, E. W. (1959). *A note on two problems in connexion with graphs*
- Edmonds, J., & Karp, R. M. (1972). *Theoretical improvements in algorithmic efficiency*
- Hopcroft, J. E., & Karp, R. M. (1973). *An n^5/2 algorithm for maximum matchings*

---

## 📝 License

This project is licensed under the MIT License - see [LICENSE](LICENSE) for details.

---

## 👤 Author

**André Pinheiro Paes**

---

## ⭐ Project Stats

- **11 algorithms** implemented
- **3 progressive parts** from basic to advanced
- **1000+ lines** of C++ code
- **Extensive documentation** in English and Portuguese



*Each algorithm tells a story. Each implementation solves real problems.*
