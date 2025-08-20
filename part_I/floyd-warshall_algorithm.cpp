#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>
#include <algorithm>
#include <iomanip>
#include "grafo.hpp"

std::vector<std::vector<double>> floydWarshall(const Grafo& grafo) {
    std::vector<int> vertices = grafo.getVertices();
    std::sort(vertices.begin(), vertices.end());
    int n = vertices.size();
    
    // Cria mapeamento índice -> vértice e vice-versa
    std::unordered_map<int, int> vertice_para_indice;
    for (int i = 0; i < n; i++) {
        vertice_para_indice[vertices[i]] = i;
    }
    
    // Inicializa matriz de distâncias
    std::vector<std::vector<double>> dist(n, std::vector<double>(n));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                dist[i][j] = 0;
            } else {
                int u = vertices[i];
                int v = vertices[j];
                dist[i][j] = grafo.peso(u, v);
            }
        }
    }
    
    // Algoritmo de Floyd-Warshall
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != std::numeric_limits<double>::infinity() &&
                    dist[k][j] != std::numeric_limits<double>::infinity()) {
                    double nova_dist = dist[i][k] + dist[k][j];
                    if (nova_dist < dist[i][j]) {
                        dist[i][j] = nova_dist;
                    }
                }
            }
        }
    }
    
    return dist;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <arquivo_grafo>" << std::endl;
        return 1;
    }
    
    std::string arquivo = argv[1];
    Grafo grafo(arquivo);
    
    auto matriz_dist = floydWarshall(grafo);
    std::vector<int> vertices = grafo.getVertices();
    std::sort(vertices.begin(), vertices.end());
    
    for (size_t i = 0; i < vertices.size(); i++) {
        std::cout << vertices[i] << ":";
        
        for (size_t j = 0; j < vertices.size(); j++) {
            if (j > 0) std::cout << ",";
            
            if (matriz_dist[i][j] == std::numeric_limits<double>::infinity()) {
                std::cout << "inf";
            } else {
                // Remove decimais desnecessários
                if (matriz_dist[i][j] == (int)matriz_dist[i][j]) {
                    std::cout << (int)matriz_dist[i][j];
                } else {
                    std::cout << matriz_dist[i][j];
                }
            }
        }
        std::cout << std::endl;
    }
    
    return 0;
}
