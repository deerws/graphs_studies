# Graph Algorithms Implementation

Study project implementing fundamental graph algorithms in C++.

## Project Structure

- `Grafo.hpp` - Graph library with all necessary functionalities
- `strongly_connected_components_SCCs.cpp` - Program to find strongly connected components
- `topological_sort.cpp` - Program for topological sorting
- `kruskal_algorithm.cpp` - Program for minimum spanning tree (Kruskal's algorithm)

## Compilation

### Linux/Mac:
```bash
g++ -std=c++11 -o strongly_connected_components_SCCs strongly_connected_components_SCCs.cpp
g++ -std=c++11 -o topological_sort topological_sort.cpp
g++ -std=c++11 -o kruskal_algorithm kruskal_algorithm.cpp
```

### Windows (MinGW):
```bash
g++ -std=c++11 -o strongly_connected_components_SCCs.exe strongly_connected_components_SCCs.cpp
g++ -std=c++11 -o topological_sort.exe topological_sort.cpp
g++ -std=c++11 -o kruskal_algorithm.exe kruskal_algorithm.cpp
```

## Usage

### Strongly Connected Components:
```bash
./strongly_connected_components_SCCs directed_graph.net
```

### Topological Sorting:
```bash
./topological_sort morning_routine.net
```

### Minimum Spanning Tree:
```bash
./kruskal_algorithm weighted_graph.net
```

## Input File Format

```
*vertices n
1 vertex_label_1
2 vertex_label_2
...
n vertex_label_n
*edges     (or *arcs for directed graphs)
source destination weight
...
```

## Example File for Strongly Connected Components

```
*vertices 7
1 V1
2 V2
3 V3
4 V4
5 V5
6 V6
7 V7
*arcs
1 2
2 6
2 3
3 4
4 5
5 3
6 7
7 6
```

**Expected Output:**
```
3,4,5
1,2,6,7
```

## Example File for Topological Sorting

```
*vertices 15
1 Wake up
2 Turn off alarm
3 Put on sandals
4 Get out of bed
5 Take shower
6 Brush teeth
7 Make coffee
8 Make scrambled eggs
9 Have breakfast
10 Wash dishes
11 Brush teeth again
12 Put on socks
13 Put on uniform
14 Put on shoes
15 Lock house
*arcs
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
10 11
11 12
12 13
13 14
14 15
```

**Expected Output:**
```
Wake up , Turn off alarm , Put on sandals , Get out of bed , Take shower , Brush teeth , Make coffee , Make scrambled eggs , Have breakfast , Wash dishes , Brush teeth again , Put on socks , Put on uniform , Put on shoes , Lock house
```

## Example File for Minimum Spanning Tree

```
*vertices 6
1 V1
2 V2
3 V3
4 V4
5 V5
6 V6
*edges
1 2 5.0
1 4 7.0
2 3 9.0
2 5 3.0
3 4 2.0
4 5 8.0
5 6 1.0
6 1 4.0
```

**Expected Output:**
```
22.0
6-5, 1-2, 3-4, 4-1, 5-2
```

## Data Structures Used

### Strongly Connected Components (Kosaraju's Algorithm)
- **Adjacency List**: `vector<vector<pair<int, double>>>` - Efficient for sparse graphs, allowing fast access to neighbors
- **Stack**: Stores vertices in DFS finishing order
- **Boolean Vector**: Marks visited vertices
- **Time Complexity**: O(V + E)

### Topological Sorting (DFS-based)
- **Adjacency List**: Same structure as above
- **Stack**: Stores topological order during DFS
- **Boolean Vector**: Controls visited vertices
- **Time Complexity**: O(V + E)

### Minimum Spanning Tree (Kruskal's Algorithm)
- **Edge Vector**: Stores and sorts all edges by weight
- **Union-Find (Disjoint Set)**: Efficiently checks for cycles
- **Set**: Avoids edge duplication in undirected graphs
- **Time Complexity**: O(E log E) due to edge sorting

## Important Notes

1. Vertex indexing in the file starts at 1, but internally the library uses 0-based indexing
2. All programs include error handling for invalid files
3. The `Grafo.hpp` library must be in the same directory as the programs or in the include path
4. Code comments are in Portuguese (Brazilian Portuguese)
