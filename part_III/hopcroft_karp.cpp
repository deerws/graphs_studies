#include <iostream>
#include "grafo.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <graph_file>" << endl;
        return 1;
    }
    
    string nomeArquivo = argv[1];
    
    // Ler grafo do arquivo
    Grafo g = Grafo::lerArquivo(nomeArquivo);
    
    int n = g.getNumVertices();
    int n1 = n / 2; // Primeira partição
    
    // Executar algoritmo de Hopcroft-Karp
    pair<int, vector<pair<int, int>>> resultado = g.hopcroftKarp(n1);
    int matching = resultado.first;
    vector<pair<int, int>> arestas = resultado.second;
    
    // Imprimir quantidade de emparelhamentos
    cout << matching << endl;
    
    // Imprimir arestas (converter para índices 1-based)
    for (size_t i = 0; i < arestas.size(); i++) {
        cout << (arestas[i].first + 1) << "-" << (arestas[i].second + 1);
        if (i < arestas.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;
    
    return 0;
}
