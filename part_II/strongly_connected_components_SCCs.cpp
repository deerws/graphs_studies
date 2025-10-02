#include <iostream>
#include "Grafo.h"

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
        
        // Encontra as componentes fortemente conexas
        vector<vector<int>> componentes = grafo.componentesFortementeConexas();
        
        // Imprime as componentes
        for (size_t i = 0; i < componentes.size(); i++) {
            for (size_t j = 0; j < componentes[i].size(); j++) {
                // Imprime o índice do vértice (somando 1 para voltar à indexação original)
                cout << componentes[i][j] + 1;
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
