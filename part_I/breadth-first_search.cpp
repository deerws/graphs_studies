#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include "grafo.hpp"

std::unordered_map<int, std::vector<int>> buscaEmLargura(const Grafo& grafo, int s) {
    std::unordered_set<int> visitado;
    std::queue<std::pair<int, int>> fila; // {vertice, nivel}
    std::unordered_map<int, std::vector<int>> niveis;
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include "grafo.hpp"

std::unordered_map<int, std::vector<int>> buscaEmLargura(const Grafo& grafo, int s) {
    std::unordered_set<int> visitado;
    std::queue<std::pair<int, int>> fila; // {vertice, nivel}
    std::unordered_map<int, std::vector<int>> niveis;
    
    fila.push({s, 0});
    
    while (!fila.empty()) {
        auto [v, nivel] = fila.front();
        fila.pop();
        
        if (visitado.find(v) != visitado.end()) {
            continue;
        }
        
        visitado.insert(v);
        niveis[nivel].push_back(v);
        
        for (int vizinho : grafo.vizinhos(v)) {
            if (visitado.find(vizinho) == visitado.end()) {
                fila.push({vizinho, nivel + 1});
            }
        }
    }
    
    return niveis;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Uso: " << argv[0] << " <arquivo_grafo> <vertice_inicial>" << std::endl;
        return 1;
    }
    
    std::string arquivo = argv[1];
    int s = std::stoi(argv[2]);
    
    Grafo grafo(arquivo);
    auto niveis = buscaEmLargura(grafo, s);
    
    // Ordena os níveis
    std::vector<int> niveis_ordenados;
    for (const auto& par : niveis) {
        niveis_ordenados.push_back(par.first);
    }
    std::sort(niveis_ordenados.begin(), niveis_ordenados.end());
    
    for (int nivel : niveis_ordenados) {
        std::cout << nivel << ": ";
        
        // Ordena vértices do nível
        std::vector<int> vertices_nivel = niveis[nivel];
        std::sort(vertices_nivel.begin(), vertices_nivel.end());
        
        for (size_t i = 0; i < vertices_nivel.size(); i++) {
            if (i > 0) std::cout << ",";
            std::cout << vertices_nivel[i];
        }
        std::cout << std::endl;
    }
    
    return 0;
}
    fila.push({s, 0});
    visitado.insert(s);
    niveis[0].push_back(s);
    
    while (!fila.empty()) {
        auto [v, nivel] = fila.front();
        fila.pop();
        
        for (int vizinho : grafo.vizinhos(v)) {
            if (visitado.find(vizinho) == visitado.end()) {
                visitado.insert(vizinho);
                int proximo_nivel = nivel + 1;
                fila.push({vizinho, proximo_nivel});
                niveis[proximo_nivel].push_back(vizinho);
            }
        }
    }
    
    return niveis;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Uso: " << argv[0] << " <arquivo_grafo> <vertice_inicial>" << std::endl;
        return 1;
    }
    
    std::string arquivo = argv[1];
    int s = std::stoi(argv[2]); // vértice inicial (1..n, conforme arquivo)
    
    Grafo grafo(arquivo);
    auto niveis = buscaEmLargura(grafo, s);
    
    // Ordena os níveis
    std::vector<int> niveis_ordenados;
    for (const auto& par : niveis) {
        niveis_ordenados.push_back(par.first);
    }
    std::sort(niveis_ordenados.begin(), niveis_ordenados.end());
    
    for (int nivel : niveis_ordenados) {
        std::cout << nivel << ": ";
        
        // Ordena vértices do nível
        std::vector<int> vertices_nivel = niveis[nivel];
        std::sort(vertices_nivel.begin(), vertices_nivel.end());
        
        for (size_t i = 0; i < vertices_nivel.size(); i++) {
            if (i > 0) std::cout << ",";
            std::cout << vertices_nivel[i];
        }
        std::cout << std::endl;
    }
    
    return 0;
}
