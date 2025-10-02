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
        // Carrega o grafo do arquivo
        Grafo grafo = Grafo::carregarDoArquivo(argv[1]);
        
        // Executa o algoritmo de Kruskal para encontrar a árvore geradora mínima
        auto resultado = grafo.kruskal();
        double pesoTotal = resultado.first;
        vector<Aresta> mst = resultado.second;
        
        // Imprime o peso total da árvore geradora mínima
        cout << fixed << setprecision(1) << pesoTotal << endl;
        
        // Imprime as arestas da árvore geradora mínima
        for (size_t i = 0; i < mst.size(); i++) {
            // Imprime no formato: origem-destino
            // Soma 1 aos índices para voltar à indexação original do arquivo
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
