#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <limits>
#include <algorithm>
#include "grafo.hpp"

struct Resultado {
    std::unordered_map<int, double> distancias;
    std::unordered_map<int, int> anterior;
};

Resultado dijkstra(const Grafo& grafo, int s) {
    std::unordered_map<int, double> dist;
    std::unordered_map<int, int> anterior;
    std::vector<int> vertices = grafo.getVertices();
    
    // Inicializa distâncias
    for (int v : vertices) {
        dist[v] = std::numeric_limits<double>::infinity();
        anterior[v] = -1;
    }
    dist[s] = 0;
    
    // Priority queue: (distancia, vertice) - min heap
    std::priority_queue<std::pair<double, int>, 
                       std::vector<std::pair<double, int>>, 
                       std::greater<>> pq;
    
    pq.push({0, s});
    std::unordered_set<int> processado;
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        
        if (processado.find(u) != processado.end()) {
            continue;
        }
        processado.insert(u);
        
        std::vector<int> vizs = grafo.vizinhos(u);
        for (int v : vizs) {
            if (processado.find(v) != processado.end()) {
                continue;
            }
            
            double peso_aresta = grafo.peso(u, v);
            double nova_dist = dist[u] + peso_aresta;
            
            if (nova_dist < dist[v]) {
                dist[v] = nova_dist;
                anterior[v] = u;
                pq.push({nova_dist, v});
            }
        }
    }
    
    return {dist, anterior};
}

std::vector<int> reconstruirCaminho(const std::unordered_map<int, int>& anterior, int s, int destino) {
    std::vector<int> caminho;
    int atual = destino;
    
    while (atual != -1) {
        caminho.push_back(atual);
        atual = anterior.at(atual);
    }
    
    std::reverse(caminho.begin(), caminho.end());
    
    // Verifica se há caminho válido
    if (caminho.empty() || caminho[0] != s) {
        return {};
    }
    
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
    auto resultado = dijkstra(grafo, s);
    
    std::vector<int> vertices = grafo.getVertices();
    std::sort(vertices.begin(), vertices.end());
    
    for (int v : vertices) {
        std::cout << v << ": ";
        
        if (resultado.distancias[v] == std::numeric_limits<double>::infinity()) {
            std::cout << "sem caminho" << std::endl;
            continue;
    
        }
        
        std::vector<int> caminho = reconstruirCaminho(resultado.anterior, s, v);
        
        for (size_t i = 0; i < caminho.size(); i++) {
            if (i > 0) std::cout << ",";
            std::cout << caminho[i];
        }
        
        std::cout << "; d=" << resultado.distancias[v] << std::endl;
    }
    
    return 0;
}
