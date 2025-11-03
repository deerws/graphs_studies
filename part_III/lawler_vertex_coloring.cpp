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
    
    // Executar algoritmo de coloração (Welsh-Powell baseado em Lawler)
    pair<int, vector<int>> resultado = g.lawler();
    int numCores = resultado.first;
    vector<int> cores = resultado.second;
    
    // Imprimir número cromático
    cout << numCores << endl;
    
    // Imprimir cores dos vértices (converter para 1-based)
    for (size_t i = 0; i < cores.size(); i++) {
        cout << (cores[i] + 1);
        if (i < cores.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;
    
    return 0;
}
