#include <iostream>
#include <iomanip>
#include "grafo.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Uso: " << argv[0] << " <arquivo_grafo>" << endl;
        return 1;
    }
    
    string nomeArquivo = argv[1];
    
    Grafo g = Grafo::lerArquivo(nomeArquivo);
    
    // Executar algoritmo de Kruskal
    pair<double, vector<pair<int, int>>> resultado = g.kruskal();
    double pesoTotal = resultado.first;
    vector<pair<int, int>> mst = resultado.second;
    
    cout << fixed << setprecision(1) << pesoTotal << endl;
    
    for (size_t i = 0; i < mst.size(); i++) {
        cout << (mst[i].first + 1) << "-" << (mst[i].second + 1);
        if (i < mst.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;
    
    return 0;
}
