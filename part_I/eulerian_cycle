#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include "grafo.hpp"

bool temCicloEuleriano(const Grafo& grafo) {
    std::vector<int> vertices = grafo.getVertices();
    if (vertices.empty()) return false;
    
    // Verifica se todos os vértices têm grau par
    for (int v : vertices) {
        if (grafo.grau(v) % 2 != 0) {
            return false;
        }
    }
    
    // Verifica conectividade usando DFS
    std::unordered_set<int> visitado;
    std::stack<int> pilha;
    
    // Encontra um vértice com grau > 0 para começar
    int inicio = -1;
    for (int v : vertices) {
        if (grafo.grau(v) > 0) {
            inicio = v;
            break;
        }
    }
    
    if (inicio == -1) return true; // Grafo sem arestas
    
    pilha.push(inicio);
    
    while (!pilha.empty()) {
        int v = pilha.top();
        pilha.pop();
        
        if (visitado.find(v) == visitado.end()) {
            visitado.insert(v);
            std::vector<int> vizs = grafo.vizinhos(v);
            for (int vizinho : vizs) {
                if (visitado.find(vizinho) == visitado.end()) {
                    pilha.push(vizinho);
                }
            }
        }
    }
    
    // Verifica se todos os vértices com grau > 0 foram visitados
    for (int v : vertices) {
        if (grafo.grau(v) > 0 && visitado.find(v) == visitado.end()) {
            return false;
        }
    }
    
    return true;
}

std::vector<int> encontrarCicloEuleriano(const Grafo& grafo) {
    if (!temCicloEuleriano(grafo)) {
        return {};
    }
    
    // Cria cópia das adjacências para manipulação
    std::unordered_map<int, std::vector<int>> adj_temp;
    std::vector<int> vertices = grafo.getVertices();
    
    for (int u : vertices) {
        std::vector<int> vizs = grafo.vizinhos(u);
        adj_temp[u] = vizs;
    }
    
    // Encontra vértice com grau > 0 para começar
    int inicio = -1;
    for (int v : vertices) {
        if (!adj_temp[v].empty()) {
            inicio = v;
            break;
        }
    }
    
    if (inicio == -1) return {}; // Sem arestas
    
    std::stack<int> pilha;
    std::vector<int> ciclo;
    
    pilha.push(inicio);
    
    while (!pilha.empty()) {
        int v = pilha.top();
        
        if (!adj_temp[v].empty()) {
            int u = adj_temp[v].back();
            adj_temp[v].pop_back();
            
            // Remove aresta reversa (grafo não-dirigido)
            auto it = std::find(adj_temp[u].begin(), adj_temp[u].end(), v);
            if (it != adj_temp[u].end()) {
                adj_temp[u].erase(it);
            }
            
            pilha.push(u);
        } else {
            ciclo.push_back(pilha.top());
            pilha.pop();
        }
    }
    
    std::reverse(ciclo.begin(), ciclo.end());
    return ciclo;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <arquivo_grafo>" << std::endl;
        return 1;
    }
    
    std::string arquivo = argv[1];
    Grafo grafo(arquivo);
    
    std::vector<int> ciclo = encontrarCicloEuleriano(grafo);
    
    if (ciclo.empty()) {
        std::cout << "0" << std::endl;
    } else {
        std::cout << "1" << std::endl;
        for (size_t i = 0; i < ciclo.size(); i++) {
            if (i > 0) std::cout << ",";
            std::cout << ciclo[i];
        }
        std::cout << std::endl;
    }
    
    return 0;
}
