#ifndef GRAFO_HPP
#define GRAFO_HPP

#include <vector>
#include <string>
#include <map>
#include <set>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <queue>
#include <stack>
#include <limits>

using namespace std;

struct Aresta {
    int destino;
    double peso;
    
    Aresta(int d, double p = 1.0) : destino(d), peso(p) {}
};

class Grafo {
private:
    int numVertices;
    bool dirigido;
    bool ponderado;
    vector<vector<Aresta>> listaAdj;
    vector<string> rotulos;
    
    // Função auxiliar para DFS no algoritmo de Kosaraju
    void dfsOrdem(int v, vector<bool>& visitado, stack<int>& pilha) {
        visitado[v] = true;
        
        for (const auto& aresta : listaAdj[v]) {
            if (!visitado[aresta.destino]) {
                dfsOrdem(aresta.destino, visitado, pilha);
            }
        }
        
        pilha.push(v);
    }
    
    // DFS para coletar componente
    void dfsComponente(int v, vector<bool>& visitado, vector<int>& componente, 
                       const vector<vector<Aresta>>& grafoTransposto) {
        visitado[v] = true;
        componente.push_back(v);
        
        for (const auto& aresta : grafoTransposto[v]) {
            if (!visitado[aresta.destino]) {
                dfsComponente(aresta.destino, visitado, componente, grafoTransposto);
            }
        }
    }
    
    // DFS para ordenação topológica
    bool dfsTopologica(int v, vector<int>& estado, stack<int>& pilha) {
        estado[v] = 1; // Visitando
        
        for (const auto& aresta : listaAdj[v]) {
            if (estado[aresta.destino] == 1) {
                return false; // Ciclo detectado
            }
            if (estado[aresta.destino] == 0) {
                if (!dfsTopologica(aresta.destino, estado, pilha)) {
                    return false;
                }
            }
        }
        
        estado[v] = 2; // Visitado
        pilha.push(v);
        return true;
    }

public:
    Grafo(int n, bool dir = false, bool pond = false) 
        : numVertices(n), dirigido(dir), ponderado(pond) {
        listaAdj.resize(n);
        rotulos.resize(n);
    }
    
    void adicionarAresta(int origem, int destino, double peso = 1.0) {
        listaAdj[origem].push_back(Aresta(destino, peso));
        if (!dirigido) {
            listaAdj[destino].push_back(Aresta(origem, peso));
        }
    }
    
    void setRotulo(int vertice, const string& rotulo) {
        if (vertice >= 0 && vertice < numVertices) {
            rotulos[vertice] = rotulo;
        }
    }
    
    string getRotulo(int vertice) const {
        if (vertice >= 0 && vertice < numVertices) {
            return rotulos[vertice];
        }
        return "";
    }
    
    int getNumVertices() const {
        return numVertices;
    }
    
    const vector<Aresta>& getAdjacentes(int vertice) const {
        return listaAdj[vertice];
    }
    
    // Algoritmo de Kosaraju para componentes fortemente conexas
    vector<vector<int>> componentesFortementeConexas() {
        vector<vector<int>> componentes;
        stack<int> pilha;
        vector<bool> visitado(numVertices, false);
        
        // Primeira DFS para obter ordem de finalização
        for (int i = 0; i < numVertices; i++) {
            if (!visitado[i]) {
                dfsOrdem(i, visitado, pilha);
            }
        }
        
        // Criar grafo transposto
        vector<vector<Aresta>> grafoTransposto(numVertices);
        for (int v = 0; v < numVertices; v++) {
            for (const auto& aresta : listaAdj[v]) {
                grafoTransposto[aresta.destino].push_back(Aresta(v, aresta.peso));
            }
        }
        
        // Segunda DFS no grafo transposto
        fill(visitado.begin(), visitado.end(), false);
        
        while (!pilha.empty()) {
            int v = pilha.top();
            pilha.pop();
            
            if (!visitado[v]) {
                vector<int> componente;
                dfsComponente(v, visitado, componente, grafoTransposto);
                componentes.push_back(componente);
            }
        }
        
        return componentes;
    }
    
    // Ordenação topológica
    vector<int> ordenacaoTopologica() {
        vector<int> ordem;
        stack<int> pilha;
        vector<int> estado(numVertices, 0); // 0: não visitado, 1: visitando, 2: visitado
        
        for (int i = 0; i < numVertices; i++) {
            if (estado[i] == 0) {
                if (!dfsTopologica(i, estado, pilha)) {
                    return vector<int>(); // Grafo tem ciclo
                }
            }
        }
        
        while (!pilha.empty()) {
            ordem.push_back(pilha.top());
            pilha.pop();
        }
        
        return ordem;
    }
    
    // Estrutura para Union-Find (para Kruskal)
    class UnionFind {
    private:
        vector<int> pai;
        vector<int> rank;
        
    public:
        UnionFind(int n) : pai(n), rank(n, 0) {
            for (int i = 0; i < n; i++) {
                pai[i] = i;
            }
        }
        
        int find(int x) {
            if (pai[x] != x) {
                pai[x] = find(pai[x]);
            }
            return pai[x];
        }
        
        bool unite(int x, int y) {
            int px = find(x);
            int py = find(y);
            
            if (px == py) return false;
            
            if (rank[px] < rank[py]) {
                pai[px] = py;
            } else if (rank[px] > rank[py]) {
                pai[py] = px;
            } else {
                pai[py] = px;
                rank[px]++;
            }
            
            return true;
        }
    };
    
    // Algoritmo de Kruskal
    pair<double, vector<pair<int, int>>> kruskal() {
        vector<tuple<double, int, int>> arestas;
        
        // Coletar todas as arestas
        for (int u = 0; u < numVertices; u++) {
            for (const auto& aresta : listaAdj[u]) {
                if (!dirigido && u > aresta.destino) continue; // Evitar duplicatas
                arestas.push_back(make_tuple(aresta.peso, u, aresta.destino));
            }
        }
        
        // Ordenar arestas por peso
        sort(arestas.begin(), arestas.end());
        
        UnionFind uf(numVertices);
        vector<pair<int, int>> mst;
        double pesoTotal = 0.0;
        
        for (const auto& aresta : arestas) {
            double peso = get<0>(aresta);
            int u = get<1>(aresta);
            int v = get<2>(aresta);
            
            if (uf.unite(u, v)) {
                mst.push_back(make_pair(u, v));
                pesoTotal += peso;
            }
        }
        
        return make_pair(pesoTotal, mst);
    }
    
    // Ler grafo de arquivo
    static Grafo lerArquivo(const string& nomeArquivo) {
        ifstream arquivo(nomeArquivo);
        string linha;
        
        // Ler número de vértices
        while (getline(arquivo, linha)) {
            if (linha.find("*vertices") != string::npos || 
                linha.find("*Vertices") != string::npos) {
                stringstream ss(linha);
                string temp;
                int n;
                ss >> temp >> n;
                
                bool dirigido = false;
                bool ponderado = false;
                
                Grafo g(n, dirigido, ponderado);
                
                // Ler rótulos
                for (int i = 0; i < n; i++) {
                    getline(arquivo, linha);
                    stringstream ss(linha);
                    int indice;
                    string rotulo;
                    ss >> indice;
                    getline(ss, rotulo);
                    
                    // Remover espaços iniciais
                    size_t start = rotulo.find_first_not_of(" \t");
                    if (start != string::npos) {
                        rotulo = rotulo.substr(start);
                    }
                    
                    g.setRotulo(indice - 1, rotulo);
                }
                
                // Ler arestas
                while (getline(arquivo, linha)) {
                    if (linha.find("*edges") != string::npos || 
                        linha.find("*Edges") != string::npos) {
                        g.dirigido = false;
                        g.ponderado = true;
                    } else if (linha.find("*arcs") != string::npos || 
                               linha.find("*Arcs") != string::npos) {
                        g.dirigido = true;
                        g.ponderado = true;
                    } else if (!linha.empty()) {
                        stringstream ss(linha);
                        int u, v;
                        double peso = 1.0;
                        ss >> u >> v;
                        if (ss >> peso) {
                            g.ponderado = true;
                        }
                        g.adicionarAresta(u - 1, v - 1, peso);
                    }
                }
                
                arquivo.close();
                return g;
            }
        }
        
        arquivo.close();
        return Grafo(0);
    }
};

#endif
