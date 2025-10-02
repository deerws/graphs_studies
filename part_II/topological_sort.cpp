#include <iostream>
#include "Grafo.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    // Verifica se o arquivo foi passado como argumento
    if (argc < 2) {
        cerr << "Uso: " << argv[0] << " <arquivo_grafo>" << endl;
        return 1;
    }
    
    try {
        // Carrega o grafo do arquivo
        Grafo grafo = Grafo::carregarDoArquivo(argv[1]);
        
        // Executa a ordenação topológica
        vector<int> ordem = grafo.ordenacaoTopologica();
        
        // Imprime a ordem topológica usando os rótulos dos vértices
        for (size_t i = 0; i < ordem.size(); i++) {
            cout << grafo.getRotulo(ordem[i]);
            if (i < ordem.size() - 1) {
                cout << " , ";
            }
        }
        cout << endl;
        
    } catch (const exception& e) {
        cerr << "Erro: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}
