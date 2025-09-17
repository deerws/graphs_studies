#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <algorithm>

class Grafo {
private:
    std::unordered_map<int, std::string> vertices; // indice -> rotulo
    std::unordered_map<int, std::unordered_map<int, double>> adjacencias; // u -> {v: peso}
    int num_vertices;
    int num_arestas;

public:
    Grafo() : num_vertices(0), num_arestas(0) {}
    
    Grafo(const std::string& arquivo) : num_vertices(0), num_arestas(0) {
        ler(arquivo);
    }
    
    int qtdVertices() const {
        return num_vertices;
    }
    
    int qtdArestas() const {
        return num_arestas;
    }
    
    int grau(int v) const {
        auto it = adjacencias.find(v);
        if (it != adjacencias.end()) {
            return it->second.size();
        }
        return 0;
    }
    
    std::string rotulo(int v) const {
        auto it = vertices.find(v);
        if (it != vertices.end()) {
            return it->second;
        }
        return "";
    }
    
    std::vector<int> vizinhos(int v) const {
        std::vector<int> viz;
        auto it = adjacencias.find(v);
        if (it != adjacencias.end()) {
            for (const auto& par : it->second) {
                viz.push_back(par.first);
            }
        }
        std::sort(viz.begin(), viz.end());
        return viz;
    }
    
    bool haAresta(int u, int v) const {
        auto it = adjacencias.find(u);
        if (it != adjacencias.end()) {
            return it->second.find(v) != it->second.end();
        }
        return false;
    }
    
    double peso(int u, int v) const {
        if (haAresta(u, v)) {
            return adjacencias.at(u).at(v);
        }
        return std::numeric_limits<double>::infinity();
    }
    
    void ler(const std::string& arquivo) {
        std::ifstream file(arquivo);
        if (!file.is_open()) {
            std::cerr << "Erro ao abrir arquivo: " << arquivo << std::endl;
            return;
        }
        
        std::string linha;
        
        // Lê primeira linha (*vertices n)
        std::getline(file, linha);
        std::istringstream iss(linha);
        std::string vertices_str;
        iss >> vertices_str >> num_vertices;
        
        // Lê rótulos dos vértices
        for (int i = 0; i < num_vertices; i++) {
            std::getline(file, linha);
            std::istringstream iss_vertex(linha);
            int indice;
            std::string rotulo_vertex;
            iss_vertex >> indice;
            
            // Pega o resto da linha como rótulo
            if (iss_vertex >> rotulo_vertex) {
                vertices[indice] = rotulo_vertex;
            } else {
                vertices[indice] = std::to_string(indice);
            }
        }
        
        // Procura por *edges
        while (std::getline(file, linha)) {
            if (linha.find("*edges") != std::string::npos) {
                break;
            }
        }
        
        // Lê arestas
        std::unordered_set<std::string> arestas_unicas;
        while (std::getline(file, linha)) {
            if (!linha.empty()) {
                std::istringstream iss_edge(linha);
                int u, v;
                double peso_aresta;
                if (iss_edge >> u >> v >> peso_aresta) {
                    // Grafo não-dirigido: adiciona em ambas as direções
                    adjacencias[u][v] = peso_aresta;
                    adjacencias[v][u] = peso_aresta;
                    
                    // Conta aresta única
                    std::string aresta_id = (u < v) ? std::to_string(u) + "-" + std::to_string(v) 
                                                    : std::to_string(v) + "-" + std::to_string(u);
                    arestas_unicas.insert(aresta_id);
                }
            }
        }
        
        num_arestas = arestas_unicas.size();
        file.close();
    }
    
    std::vector<int> getTodosVertices() const {
        std::vector<int> todos;
        for (const auto& par : vertices) {
            todos.push_back(par.first);
        }
        std::sort(todos.begin(), todos.end());
        return todos;
    }
};

#endif
