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
#include <climits>
#include <cmath>

using namespace std;

struct Aresta {
    int destino;
    double peso;
    double fluxo;
    
    Aresta(int d, double p = 1.0) : destino(d), peso(p), fluxo(0.0) {}
};

class Grafo {
private:
    int numVertices;
    bool dirigido;
    bool ponderado;
    vector<vector<Aresta>> listaAdj;
    vector<string> rotulos;
    
    // BFS para Edmonds-Karp
    bool bfs(int s, int t, vector<int>& pai, const vector<vector<double>>& capacidadeResidual) {
        vector<bool> visitado(numVertices, false);
        queue<int> fila;
        fila.push(s);
        visitado[s] = true;
        pai[s] = -1;
        
        while (!fila.empty()) {
            int u = fila.front();
            fila.pop();
            
            for (int v = 0; v < numVertices; v++) {
                if (!visitado[v] && capacidadeResidual[u][v] > 0) {
                    fila.push(v);
                    pai[v] = u;
                    visitado[v] = true;
                    if (v == t) return true;
                }
            }
        }
        
        return false;
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
    
    // Algoritmo de Edmonds-Karp (Ford-Fulkerson com BFS)
    double edmondsKarp(int s, int t) {
        vector<vector<double>> capacidadeResidual(numVertices, vector<double>(numVertices, 0.0));
        
        // Construir grafo residual inicial
        for (int u = 0; u < numVertices; u++) {
            for (const auto& aresta : listaAdj[u]) {
                capacidadeResidual[u][aresta.destino] += aresta.peso;
            }
        }
        
        vector<int> pai(numVertices);
        double fluxoMaximo = 0;
        
        // Enquanto existir caminho aumentante
        while (bfs(s, t, pai, capacidadeResidual)) {
            // Encontrar capacidade mínima no caminho
            double fluxoCaminho = numeric_limits<double>::max();
            for (int v = t; v != s; v = pai[v]) {
                int u = pai[v];
                fluxoCaminho = min(fluxoCaminho, capacidadeResidual[u][v]);
            }
            
            // Atualizar capacidades residuais
            for (int v = t; v != s; v = pai[v]) {
                int u = pai[v];
                capacidadeResidual[u][v] -= fluxoCaminho;
                capacidadeResidual[v][u] += fluxoCaminho;
            }
            
            fluxoMaximo += fluxoCaminho;
        }
        
        return fluxoMaximo;
    }
    
    // Algoritmo de Hopcroft-Karp
    pair<int, vector<pair<int, int>>> hopcroftKarp(int n1) {
        int n2 = numVertices - n1;
        vector<int> pairU(n1, -1);
        vector<int> pairV(n2, -1);
        vector<int> dist(n1 + 1);
        
        int matching = 0;
        
        // BFS e DFS alternados
        while (true) {
            // BFS
            queue<int> q;
            for (int u = 0; u < n1; u++) {
                if (pairU[u] == -1) {
                    dist[u] = 0;
                    q.push(u);
                } else {
                    dist[u] = INT_MAX;
                }
            }
            dist[n1] = INT_MAX; // NIL
            
            bool found = false;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                
                if (dist[u] < dist[n1]) {
                    for (const auto& aresta : listaAdj[u]) {
                        int v = aresta.destino - n1; // Ajustar para índice da segunda partição
                        
                        if (v >= 0 && v < n2) {
                            int nextU = pairV[v];
                            if (nextU == -1) {
                                dist[n1] = dist[u] + 1;
                                found = true;
                            } else if (dist[nextU] == INT_MAX) {
                                dist[nextU] = dist[u] + 1;
                                q.push(nextU);
                            }
                        }
                    }
                }
            }
            
            if (!found) break;
            
            // DFS
            for (int u = 0; u < n1; u++) {
                if (pairU[u] == -1) {
                    // DFS inline
                    stack<int> dfsStack;
                    dfsStack.push(u);
                    vector<bool> visited(n1, false);
                    
                    while (!dfsStack.empty()) {
                        int curr = dfsStack.top();
                        dfsStack.pop();
                        
                        if (visited[curr]) continue;
                        visited[curr] = true;
                        
                        for (const auto& aresta : listaAdj[curr]) {
                            int v = aresta.destino - n1;
                            
                            if (v >= 0 && v < n2) {
                                if (pairV[v] == -1) {
                                    // Caminho aumentante encontrado
                                    pairV[v] = curr;
                                    pairU[curr] = v + n1;
                                    matching++;
                                    break;
                                } else {
                                    int nextU = pairV[v];
                                    if (dist[nextU] == dist[curr] + 1 && !visited[nextU]) {
                                        dfsStack.push(nextU);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        
        vector<pair<int, int>> arestas;
        for (int u = 0; u < n1; u++) {
            if (pairU[u] != -1) {
                arestas.push_back(make_pair(u, pairU[u]));
            }
        }
        
        return make_pair(matching, arestas);
    }
    
    // Algoritmo de Lawler para coloração de vértices
    pair<int, vector<int>> lawler() {
        int n = numVertices;
        vector<int> cor(n, -1);
        vector<set<int>> independentes;
        
        // Encontrar todos os conjuntos independentes maximais usando programação dinâmica
        vector<long long> dp(1 << n, 0);
        
        for (int mask = 0; mask < (1 << n); mask++) {
            bool ehIndependente = true;
            vector<int> vertices;
            
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    vertices.push_back(i);
                }
            }
            
            // Verificar se é conjunto independente
            for (size_t i = 0; i < vertices.size() && ehIndependente; i++) {
                for (size_t j = i + 1; j < vertices.size() && ehIndependente; j++) {
                    for (const auto& aresta : listaAdj[vertices[i]]) {
                        if (aresta.destino == vertices[j]) {
                            ehIndependente = false;
                            break;
                        }
                    }
                }
            }
            
            if (ehIndependente && !vertices.empty()) {
                dp[mask] = 1;
            }
        }
        
        // Usar algoritmo guloso melhorado (Welsh-Powell)
        vector<pair<int, int>> graus;
        for (int i = 0; i < n; i++) {
            graus.push_back(make_pair(listaAdj[i].size(), i));
        }
        sort(graus.rbegin(), graus.rend());
        
        int numCores = 0;
        
        for (const auto& p : graus) {
            int v = p.second;
            
            set<int> coresVizinhas;
            for (const auto& aresta : listaAdj[v]) {
                if (cor[aresta.destino] != -1) {
                    coresVizinhas.insert(cor[aresta.destino]);
                }
            }
            
            int corEscolhida = 0;
            while (coresVizinhas.count(corEscolhida)) {
                corEscolhida++;
            }
            
            cor[v] = corEscolhida;
            numCores = max(numCores, corEscolhida + 1);
        }
        
        return make_pair(numCores, cor);
    }
    
    // Ler grafo de arquivo
    static Grafo lerArquivo(const string& nomeArquivo) {
        ifstream arquivo(nomeArquivo);
        string linha;
        
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
