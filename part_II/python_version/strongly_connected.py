import sys
from grafo import Grafo

def main():
    if len(sys.argv) < 2:
        print(f"Uso: {sys.argv[0]} <arquivo_grafo>", file=sys.stderr)
        return 1
    
    try:
        grafo = Grafo.carregar_do_arquivo(sys.argv[1])
        componentes = grafo.componentes_fortemente_conexas()
        
        # Imprime as componentes
        for componente in componentes:
            vertices_str = []
            for vertice in componente:
                vertices_str.append(str(vertice + 1))  # índice do vértice
            print(",".join(vertices_str))
        
    except Exception as e:
        print(f"Erro: {e}", file=sys.stderr)
        return 1
    
    return 0

if __name__ == "__main__":
    sys.exit(main())
