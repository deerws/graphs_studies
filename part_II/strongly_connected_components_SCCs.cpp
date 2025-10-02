#include <iostream>
#include "Grafo.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Uso: " << argv[0] << " <arquivo_grafo>" << endl;
        return 1;
    }
    
    try {
        Grafo grafo = Grafo::carregarDoArquivo(argv[1]);
        vector<vector<int>> componentes = grafo.componentesFortementeConexas();
        
        // Imprime as componentes
        for (size_t i = 0; i < componentes.size(); i++) {
            for (size_t j = 0; j < componentes[i].size(); j++) {
                cout << componentes[i][j] + 1; // índice do vértice
                if (j < componentes[i].size() - 1) {
                    cout << ",";
                }
            }
            cout << endl;
        }
        
    } catch (const exception& e) {
        cerr << "Erro: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}
