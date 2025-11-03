#include <iostream>
#include <iomanip>
#include "grafo.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 4) {
        cerr << "Usage: " << argv[0] << " <graph_file> <source> <sink>" << endl;
        return 1;
    }
    
    string nomeArquivo = argv[1];
    int s = stoi(argv[2]) - 1; // Converter para índice 0
    int t = stoi(argv[3]) - 1;
    
    // Ler grafo do arquivo
    Grafo g = Grafo::lerArquivo(nomeArquivo);
    
    // Executar algoritmo de Edmonds-Karp
    double fluxoMaximo = g.edmondsKarp(s, t);
    
    // Imprimir resultado (sem casas decimais se for inteiro)
    if (fluxoMaximo == (int)fluxoMaximo) {
        cout << (int)fluxoMaximo << endl;
    } else {
        cout << fixed << setprecision(1) << fluxoMaximo << endl;
    }
    
    return 0;
}
