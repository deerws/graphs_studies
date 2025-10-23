#include <iostream>
#include <algorithm>
#include "grafo.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Uso: " << argv[0] << " <arquivo_grafo>" << endl;
        return 1;
    }
    
    string nomeArquivo = argv[1];
    Grafo g = Grafo::lerArquivo(nomeArquivo);

    vector<vector<int>> componentes = g.componentesFortementeConexas();
    
    for (const auto& componente : componentes) {
        vector<int> comp = componente;
        sort(comp.begin(), comp.end());
        
        for (size_t i = 0; i < comp.size(); i++) {
            cout << (comp[i] + 1);
            if (i < comp.size() - 1) {
                cout << ",";
            }
        }
        cout << endl;
    }
    
    return 0;
}
