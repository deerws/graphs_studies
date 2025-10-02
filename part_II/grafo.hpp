#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <stack>
#include <queue>
#include <limits>
#include <fstream>
#include <sstream>

using namespace std;

// Estrutura para representar uma aresta ponderada
struct Aresta {
    int origem;
    int destino;
    double peso;
    
    Aresta(int o, int d, double p) : origem(o), destino(d), peso(p) {}
    
    // Operador para ordenação por peso (usado no Kruskal)
    bool operator<(const Aresta& outra) const {
        return peso < outra.peso;
    }
};

class Grafo {
private:
    int numVertices;
    bool dirigido;
    bool ponderado;
    vector<string> rotulos;  // Rótulos dos vértices
    vector<vector<pair<int, double>>> listaAdj;  // Lista de adjacência (vértice, peso)
    
public:
    // Construtor
    Grafo(int n, bool dir = false, bool pond = false) 
        : numVertices(n), dirigido(dir), ponderado(pond) {
        listaAdj.resize(n);
        rotulos.resize(n);
    }
    
    // Adiciona uma aresta ao grafo
    void adicionarAresta(int origem, int destino, double peso = 1.0) {
        listaAdj[origem].push_back({destino, peso});
        if (!dirigido) {
            listaAdj[destino].push_back({origem, peso});
        }
    }
    
    // Define o rótulo de um vértice
    void setRotulo(int vertice, const string& rotulo) {
        if (vertice >= 0 && vertice < numVertices) {
            rotulos[vertice] = rotulo;
        }
    }
    
    // Retorna o rótulo de um vértice
    string getRotulo(int vertice) const {
        if (vertice >= 0 && vertice < numVertices) {
            return rotulos[vertice];
        }
        return "";
    }
    
    // Retorna o número de vértices
    int getNumVertices() const {
        return numVertices;
    }
    
    // Retorna se o grafo é dirigido
    bool isDirigido() const {
        return dirigido;
    }
    
    // Retorna a lista de adjacência de um vértice
    const vector<pair<int, double>>& getAdjacentes(int vertice) const {
        return listaAdj[vertice];
    }
    
    // DFS auxiliar para encontrar componentes fortemente conexas (Kosaraju)
    void dfsOrdem(int v, vector<bool>& visitado, stack<int>& pilha) {
        visitado[v] = true;
        
        for (const auto& adj : listaAdj[v]) {
            if (!visitado[adj.first]) {
                dfsOrdem(adj.first, visitado, pilha);
            }
        }
        
        pilha.push(v);
    }
    
    // DFS para coletar componentes
    void dfsComponente(int v, vector<bool>& visitado, vector<int>& componente, 
                       const vector<vector<int>>& grafoTransposto) {
        visitado[v] = true;
        componente.push_back(v);
        
        for (int adj : grafoTransposto[v]) {
            if (!visitado[adj]) {
                dfsComponente(adj, visitado, componente, grafoTransposto);
            }
        }
    }
    
    // Encontra componentes fortemente conexas usando algoritmo de Kosaraju
    vector<vector<int>> componentesFortementeConexas() {
        stack<int> pilha;
        vector<bool> visitado(numVertices, false);
        
        // Passo 1: Preencher a pilha com ordem de finalização da DFS
        for (int i = 0; i < numVertices; i++) {
            if (!visitado[i]) {
                dfsOrdem(i, visitado, pilha);
            }
        }
        
        // Passo 2: Criar grafo transposto
        vector<vector<int>> grafoTransposto(numVertices);
        for (int v = 0; v < numVertices; v++) {
            for (const auto& adj : listaAdj[v]) {
                grafoTransposto[adj.first].push_back(v);
            }
        }
        
        // Passo 3: Fazer DFS no grafo transposto na ordem da pilha
        fill(visitado.begin(), visitado.end(), false);
        vector<vector<int>> componentes;
        
        while (!pilha.empty()) {
            int v = pilha.top();
            pilha.pop();
            
            if (!visitado[v]) {
                vector<int> componente;
                dfsComponente(v, visitado, componente, grafoTransposto);
                sort(componente.begin(), componente.end());
                componentes.push_back(componente);
            }
        }
        
        return componentes;
    }
    
    // DFS auxiliar para ordenação topológica
    void dfsTopologica(int v, vector<bool>& visitado, stack<int>& pilha) {
        visitado[v] = true;
        
        for (const auto& adj : listaAdj[v]) {
            if (!visitado[adj.first]) {
                dfsTopologica(adj.first, visitado, pilha);
            }
        }
        
        pilha.push(v);
    }
    
    // Ordenação topológica
    vector<int> ordenacaoTopologica() {
        stack<int> pilha;
        vector<bool> visitado(numVertices, false);
        
        for (int i = 0; i < numVertices; i++) {
            if (!visitado[i]) {
                dfsTopologica(i, visitado, pilha);
            }
        }
        
        vector<int> ordem;
        while (!pilha.empty()) {
            ordem.push_back(pilha.top());
            pilha.pop();
        }
        
        return ordem;
    }
    
    // Retorna todas as arestas do grafo
    vector<Aresta> getArestas() const {
        vector<Aresta> arestas;
        set<pair<int, int>> adicionadas;  // Para evitar duplicatas em grafos não-dirigidos
        
        for (int v = 0; v < numVertices; v++) {
            for (const auto& adj : listaAdj[v]) {
                if (dirigido || adicionadas.find({adj.first, v}) == adicionadas.end()) {
                    arestas.push_back(Aresta(v, adj.first, adj.second));
                    adicionadas.insert({v, adj.first});
                }
            }
        }
        
        return arestas;
    }
    
    // Algoritmo de Kruskal para árvore geradora mínima
    pair<double, vector<Aresta>> kruskal() {
        vector<Aresta> arestas = getArestas();
        sort(arestas.begin(), arestas.end());
        
        // Union-Find
        vector<int> pai(numVertices);
        for (int i = 0; i < numVertices; i++) {
            pai[i] = i;
        }
        
        // Função para encontrar raiz (com compressão de caminho)
        function<int(int)> find = [&](int x) {
            if (pai[x] != x) {
                pai[x] = find(pai[x]);
            }
            return pai[x];
        };
        
        // Função para unir conjuntos
        auto unionSet = [&](int x, int y) {
            int raizX = find(x);
            int raizY = find(y);
            if (raizX != raizY) {
                pai[raizX] = raizY;
            }
        };
        
        vector<Aresta> mst;
        double pesoTotal = 0.0;
        
        for (const auto& aresta : arestas) {
            if (find(aresta.origem) != find(aresta.destino)) {
                mst.push_back(aresta);
                pesoTotal += aresta.peso;
                unionSet(aresta.origem, aresta.destino);
                
                if (mst.size() == numVertices - 1) {
                    break;
                }
            }
        }
        
        return {pesoTotal, mst};
    }
    
    // Carrega grafo de um arquivo
    static Grafo carregarDoArquivo(const string& nomeArquivo) {
        ifstream arquivo(nomeArquivo);
        if (!arquivo.is_open()) {
            throw runtime_error("Não foi possível abrir o arquivo: " + nomeArquivo);
        }
        
        string linha;
        int numVertices = 0;
        bool dirigido = false;
        bool ponderado = false;
        
        // Ler número de vértices
        while (getline(arquivo, linha)) {
            if (linha.find("*vertices") != string::npos) {
                istringstream iss(linha);
                string temp;
                iss >> temp >> numVertices;
                break;
            }
        }
        
        Grafo grafo(numVertices);
        
        // Ler rótulos dos vértices
        for (int i = 0; i < numVertices; i++) {
            getline(arquivo, linha);
            istringstream iss(linha);
            int indice;
            iss >> indice;
            
            string rotulo;
            getline(iss, rotulo);
            // Remove espaços iniciais
            rotulo.erase(0, rotulo.find_first_not_of(" \t\r\n"));
            grafo.setRotulo(indice - 1, rotulo);
        }
        
        // Ler arestas
        while (getline(arquivo, linha)) {
            if (linha.find("*edges") != string::npos) {
                dirigido = false;
                ponderado = true;
                break;
            } else if (linha.find("*arcs") != string::npos) {
                dirigido = true;
                ponderado = true;
                break;
            }
        }
        
        grafo.dirigido = dirigido;
        grafo.ponderado = ponderado;
        
        while (getline(arquivo, linha)) {
            if (linha.empty() || linha[0] == '*') continue;
            
            istringstream iss(linha);
            int origem, destino;
            double peso = 1.0;
            
            iss >> origem >> destino;
            if (iss >> peso) {
                ponderado = true;
            }
            
            grafo.adicionarAresta(origem - 1, destino - 1, peso);
        }
        
        arquivo.close();
        return grafo;
    }
};

#endif // GRAFO_H
