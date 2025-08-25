#include <iostream>
#include <vector>
#include <algorithm>
#include "grafo.hpp"

// Estrutura Union-Find (Disjoint Set Union - DSU)
class DSU {
private:
    std::vector<int> parent, rank;
public:
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; i++) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return false;
        if (rank[rx] < rank[ry]) std::swap(rx, ry);
        parent[ry] = rx;
        if (rank[rx] == rank[ry]) rank[rx]++;
        return true;
    }
};

struct Aresta {
    int u, v;
    double w;
};

// Implementação do Kruskal
std::pair<double, std::vector<Aresta>> kruskal(const Grafo& grafo) {
    int n = grafo.qtdVertices();
    std::vector<Aresta> arestas;

    // monta lista de arestas
    for (int u = 1; u <= n; u++) {
        for (int v : grafo.vizinhos(u)) {
            if (u < v) { // evita duplicar aresta (grafo não direcionado)
                double w = grafo.peso(u, v);
                arestas.push_back({u, v, w});
            }
        }
    }

    // ordena por peso
    std::sort(arestas.begin(), arestas.end(), [](const Aresta& a, const Aresta& b) {
        return a.w < b.w;
    });

    DSU dsu(n);
    double peso_total = 0;
    std::vector<Aresta> mst;

    for (const auto& e : arestas) {
        if (dsu.unite(e.u, e.v)) {
            peso_total += e.w;
            mst.push_back(e);
        }
    }

    return {peso_total, mst};
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <arquivo_grafo>" << std::endl;
        return 1;
    }

    std::string arquivo = argv[1];
    Grafo grafo(arquivo);

    auto [peso_total, mst] = kruskal(grafo);

    std::cout << "Peso total = " << peso_total << std::endl;
    std::cout << "Arestas:" << std::endl;
    for (auto& e : mst) {
        std::cout << e.u << "-" << e.v << " (" << e.w << ")" << std::endl;
    }

    return 0;
}
