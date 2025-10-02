#include <iostream>
#include <iomanip>
#include "Grafo.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    // Verifica se o arquivo foi passado como argumento
    if (argc < 2) {
        cerr << "Uso: " << argv[0] << " <arquivo_grafo>" << endl;
        return 1;
    }
    
    try {
        Grafo grafo = Grafo::carregarDoArquivo(argv[1]);
        
        auto resultado = grafo.kruskal();
        double pesoTotal = resultado.first;
        vector<Aresta> mst = resultado.second;
        
        cout << fixed << setprecision(1) << pesoTotal << endl;
        
        // Imprime as arestas no formato origem-destino
        for (size_t i = 0; i < mst.size(); i++) {
            cout << mst[i].origem + 1 << "-" << mst[i].destino + 1;
            if (i < mst.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
        
    } catch (const exception& e) {
        cerr << "Erro: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}
