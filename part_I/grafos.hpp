#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <vector>
#include <string>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include <limits>
#include <stdexcept>

class Grafo {
private:
    int n_vertices;
    int n_arestas;
    std::vector<std::vector<std::pair<int, double>>> adj; // lista de adjacência {vizinho, peso}
    std::unordered_map<int, std::string> rotulos;         // índice -> rótulo

public:
    Grafo(const std::string& arquivo) {
        std::ifstream in(arquivo);
        if (!in.is_open()) {
            throw std::runtime_error("Erro ao abrir arquivo: " + arquivo);
        }

        std::string token;
        in >> token; // deve ser "*vertices"
        if (token != "*vertices") {
            throw std::runtime_error("Formato inválido: esperado *vertices");
        }

        in >> n_vertices;
        adj.resize(n_vertices + 1); // índices de 1 a n
        n_arestas = 0;

        // lê rótulos
        for (int i = 1; i <= n_vertices; i++) {
            int idx;
            std::string rotulo;
            in >> idx >> rotulo;
            rotulos[idx] = rotulo;
        }

        // lê edges
        in >> token;
        if (token != "*edges") {
            throw std::runtime_error("Formato inválido: esperado *edges");
        }

        int u, v;
        double w;
        while (in >> u >> v >> w) {
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
            n_arestas++;
        }
    }

    int qtdVertices() const { return n_vertices; }

    int qtdArestas() const { return n_arestas; }

    int grau(int v) const { return adj[v].size(); }

    std::string rotulo(int v) const {
        auto it = rotulos.find(v);
        if (it != rotulos.end()) return it->second;
        return "";
    }

    std::vector<int> vizinhos(int v) const {
        std::vector<int> vs;
        for (auto [viz, peso] : adj[v]) vs.push_back(viz);
        return vs;
    }

    bool haAresta(int u, int v) const {
        for (auto [viz, peso] : adj[u]) {
            if (viz == v) return true;
        }
        return false;
    }

    double peso(int u, int v) const {
        for (auto [viz, w] : adj[u]) {
            if (viz == v) return w;
        }
        return std::numeric_limits<double>::inf_
