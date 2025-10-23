#include <iostream>
#include "grafo.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Uso: " << argv[0] << " <arquivo_grafo>" << endl;
        return 1;
    }
    
    string nomeArquivo = argv[1];
    
    Grafo g = Grafo::lerArquivo(nomeArquivo);
    
    // Executar ordenação topológica
    vector<int> ordem = g.ordenacaoTopologica();
    
    if (ordem.empty()) {
        cerr << "Erro: O grafo contém ciclos. Não é possível fazer ordenação topológica." << endl;
        return 1;
    }
    
    for (size_t i = 0; i < ordem.size(); i++) {
        cout << g.getRotulo(ordem[i]);
        if (i < ordem.size() - 1) {
            cout << " , ";
        }
    }
    cout << endl;
    
    return 0;
}
