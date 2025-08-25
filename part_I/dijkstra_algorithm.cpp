#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <unordered_map>
#include "grafo.hpp"

struct Node {
    int v;
    double dist;
    bool operator>(const Node& other) const {
        return dist > other.dist;
    }
};

std::unordered_map<int, double> dijkstra(const Grafo& grafo, int s, std::unordered_map<int, int>& antecessor) {
    int n = grafo.qtdVertices();
    std::unordered_map<int, double> dist;
    antecessor.clear();

    // Inicializa distâncias
    for (int v = 1; v <= n; v++) {
        dist[v] = std::numeric_limits<double>::infinity();
        antecessor[v] = -1;
    }
    dist[s] = 0;

    // Min-heap
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> pq;
    pq.push({s, 0});

    while (!pq.empty()) {
        Node atual = pq.top();
        pq.pop();
        int u = atual.v;

        // Relaxamento
        for (int viz : grafo.vizinhos(u)) {
            double peso = grafo.peso(u, viz);
            if (dist[u] + peso < dist[viz]) {
                dist[viz] = dist[u] + peso;
                antecessor[viz] = u;
                pq.push({viz, dist[viz]});
            }
        }
    }

    return dist;
}

// Reconstrói caminho de s até v usando antecessores
std::vector<int> reconstruirCaminho(int v, const std::unordered_map<int, int>& antecessor) {
    std::vector<int> caminho;
    for (int atual = v; atual != -1; atual = antecessor.at(atual)) {
        caminho.push_back(atual);
    }
    std::reverse(caminho.begin(), caminho.end());
    return caminho;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Uso: " << argv[0] << " <arquivo_grafo> <vertice_inicial>" << std::endl;
        return 1;
    }

    std::string arquivo = argv[1];
    int s = std::stoi(argv[2]);

    Grafo grafo(arquivo);
    std::unordered_map<int, int> antecessor;
    auto dist = dijkstra(grafo, s, antecessor);

    // Imprime saída no formato pedido
    for (int v = 1; v <= grafo.qtdVertices(); v++) {
        std::cout << v << ": ";

        auto caminho = reconstruirCaminho(v, antecessor);
        for (size_t i = 0; i < caminho.size(); i++) {
            if (i > 0) std::cout << ",";
            std::cout << caminho[i];
        }

        std::cout << "; d=";
        if (dist[v] == std::numeric_limits<double>::infinity())
            std::cout << "inf";
        else
            std::cout << dist[v];
        std::cout << std::endl;
    }

    return 0;
}
