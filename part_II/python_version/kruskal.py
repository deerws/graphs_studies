import sys
from grafo import Grafo

def main():
    # Verifica se o arquivo foi passado como argumento
    if len(sys.argv) < 2:
        print(f"Uso: {sys.argv[0]} <arquivo_grafo>", file=sys.stderr)
        return 1
    
    try:
        grafo = Grafo.carregar_do_arquivo(sys.argv[1])
        
        peso_total, mst = grafo.kruskal()
        
        print(f"{peso_total:.1f}")
        
        # Imprime as arestas no formato origem-destino
        arestas_str = []
        for aresta in mst:
            arestas_str.append(f"{aresta.origem + 1}-{aresta.destino + 1}")
        
        print(", ".join(arestas_str))
        
    except Exception as e:
        print(f"Erro: {e}", file=sys.stderr)
        return 1
    
    return 0

if __name__ == "__main__":
    sys.exit(main())
