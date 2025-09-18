# Graph Theory Projects 📊

Implementations of classical **graph theory algorithms** and data structures in **C++17**.  
The focus is on **efficiency, and clarity**.

---

## 📚 Contents

### A1 – Graph Fundamentals
- **Graph Representation**: Weighted, undirected graphs with efficient O(1) operations  
- **Breadth-First Search (BFS)**: Level-order traversal and connected component exploration  
- **Eulerian Cycle Detection**: Hierholzer’s algorithm for Eulerian cycles  
- **Shortest Paths (Dijkstra)**: Single-source shortest path with priority queue optimization  
- **All-Pairs Shortest Paths (Floyd-Warshall)**: Dynamic programming approach for weighted graphs  
- **Bonus – Minimum Spanning Tree (Kruskal)**: Greedy algorithm for MST construction  

---

## 🛠️ Tech Stack

- **Language**: C++17  
- **Build System**: GNU Make  
- **Data Structures**: Adjacency lists, hash maps, priority queues, disjoint set (union-find)  
- **Paradigms**: Greedy algorithms, dynamic programming, graph traversal  

---

## ⚡ Usage

### Requirements
- C++17 compatible compiler (GCC, Clang, or MSVC)  
- `make` (optional, for automated builds)  

### Compilation
```bash
# Clone the repository
git clone https://github.com/deerws/graphs_studies.git
cd part_I

# Compile all programs
make all

# Or compile a specific program (example: BFS)
make bfs
```

### Running
```bash
# Example: BFS from vertex 8
./bfs example.net 8

# Example: Dijkstra from vertex 2
./dijkstra example.net 2

# Example: Kruskal MST
./kruskal example.net
```

---

## 📊 Input Format

Graph files use the **.net format**:

```
*vertices n
1 "Label_1"
2 "Label_2"
...
n "Label_n"
*edges
u v weight
x y weight
...
```

- Vertices are indexed from **1 to n**  
- Graphs are **undirected and weighted**  

---

## 🏆 Key Features

- ✅ **Optimized algorithms** with correct complexity analysis  
- ✅ **Robust implementations** (handles edge cases and disconnected graphs)  
- ✅ **Clean & modular code** designed for education and reuse  
- ✅ **Academic compliance** with INE5413 requirements  
- ✅ **Extra content** (Minimum Spanning Tree – Kruskal)  

---

## 📈 Algorithm Summary

| Algorithm        | Time Complexity     | Space Complexity | Use Case                          |
|------------------|---------------------|------------------|-----------------------------------|
| BFS              | O(V + E)            | O(V)             | Graph traversal, unweighted paths |
| Eulerian Cycle   | O(V + E)            | O(E)             | Cycle detection                   |
| Dijkstra         | O((V + E) log V)    | O(V)             | Shortest paths from one source    |
| Floyd-Warshall   | O(V³)               | O(V²)            | All-pairs shortest paths          |
| Kruskal (MST)    | O(E log V)          | O(V + E)         | Minimum spanning tree             |

---

## 📝 Example Execution

Consider the following graph (`example.net`):

```
*vertices 5
1 A
2 B
3 C
4 D
5 E
*edges
1 2 2
1 3 4
2 3 1
2 4 7
3 5 3
4 5 1
```

### BFS (starting at vertex 1)
```bash
./bfs example.net 1
```
Output:
```
0: 1
1: 2,3
2: 4,5
```

### Dijkstra (starting at vertex 2)
```bash
./dijkstra example.net 2
```
Output:
```
1: 2,1; d=2
2: 2; d=0
3: 2,3; d=1
4: 2,3,5,4; d=5
5: 2,3,5; d=4
```

### Kruskal (MST)
```bash
./kruskal example.net
```
Output:
```
Peso total = 7
Arestas:
2-3 (1)
4-5 (1)
1-2 (2)
3-5 (3)
```

---

## 📄 License

This repository is for **educational purposes**.  
Feel free to use, adapt, and learn from it.  
