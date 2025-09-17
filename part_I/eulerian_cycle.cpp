#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <algorithm>
#include "grafo.hpp"

bool temCicloEuleriano(const Grafo& grafo) {
    std::vector<int> vertices = grafo.getTodosVertices();
    
    // Verifica se todos os vértices têm grau par
    for (int v : vertices) {
        if (grafo.grau(v) % 2 != 0) {
            return false;
        }
    }
    
    // Verifica conectividade usando DFS
    if (vertices.empty()) return false;
    
    std::unordered_set<int> visitados;
    std::stack<int> pilha;
    pilha.push(vertices[0]);
    
    while (!pilha.empty()) {
        int v = pilha.top();
        pilha.pop();
        
        if (visitados.find(v) != visitados.end()) {
            continue;
        }
        
        visitados.insert(v);
        
        for (int vizinho : grafo.vizinhos(v)) {
            if (visitados.find(vizinho) == visitados.end()) {
                pilha.push(vizinho);
            }
        }
    }
    
    // Verifica se todos os vértices com grau > 0 foram visitados
    for (int v : vertices) {
        if (grafo.grau(v) > 0 && visitados.find(v) == visitados.end()) {
            return false;
        }
    }
    
    return true;
}

std::vector<int> encontrarCicloEuleriano(const Grafo& grafo) {
    if (!temCicloEuleriano(grafo)) {
        return {};
    }
    
    // Cria cópia das adjacências para remover arestas
    std::unordered_map<int, std::vector<int>> adj_copy;
    std::vector<int> vertices = grafo.getTodosVertices();
    
    for (int v : vertices) {
        adj_copy[v] = grafo.vizinhos(v);
    }
    
    // Encontra vértice inicial (qualquer um com grau > 0)
    int inicio = -1;
    for (int v : vertices) {
        if (!adj_copy[v].empty()) {
            inicio = v;
            break;
        }
    }
    
    if (inicio == -1) {
        return {};
    }
    
    std::stack<int> pilha;
    std::vector<int> ciclo;
    pilha.push(inicio);
    
    while (!pilha.empty()) {
        int v = pilha.top();
        
        if (!adj_copy[v].empty()) {
            // Pega próximo vizinho
            int u = adj_copy[v].back();
            adj_copy[v].pop_back();
            
            // Remove aresta u-v também
            auto it = std::find(adj_copy[u].begin(), adj_copy[u].end(), v);
            if (it != adj_copy[u].end()) {
                adj_copy[u].erase(it);
            }
            
            pilha.push(u);
        } else {
            // Não há mais arestas, adiciona ao ciclo
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
        for (size_t i = 0; i < ciclo.size() - 1; i++) {
            if (i > 0) std::cout << ",";
            std::cout << ciclo[i];
        }
        std::cout << std::endl;
    }
    
    return 0;
}

