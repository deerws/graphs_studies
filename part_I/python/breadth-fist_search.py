import sys
from collections import deque
from grafo import Grafo

def busca_largura(grafo, s):
    """Realiza busca em largura a partir do vértice s"""
    visitados = set()
    fila = deque([(s, 0)])  # (vértice, nível)
    niveis = {}
    
    while fila:
        v, nivel = fila.popleft()
        
        if v in visitados:
            continue
            
        visitados.add(v)
        
        if nivel not in niveis:
            niveis[nivel] = []
        niveis[nivel].append(v)
        
        # Adiciona vizinhos à fila
        for vizinho in sorted(grafo.vizinhos(v)):
            if vizinho not in visitados:
                fila.append((vizinho, nivel + 1))
    
    return niveis

def main():
    if len(sys.argv) != 3:
        print("Uso: python3 A1_2.py <arquivo_grafo> <vertice_inicial>")
        return
    
    arquivo = sys.argv[1]
    s = int(sys.argv[2])
    
    grafo = Grafo()
    grafo.ler(arquivo)
    
    niveis = busca_largura(grafo, s)
    
    # Imprime resultado
    for nivel in sorted(niveis.keys()):
        vertices = sorted(niveis[nivel])
        print(f"{nivel}: {','.join(map(str, vertices))}")

if __name__ == "__main__":
    main()
