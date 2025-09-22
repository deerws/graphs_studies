import sys
import math
from grafo import Grafo

def floyd_warshall(grafo: Grafo) -> List[List[float]]:
    vertices = grafo.get_vertices()
    n = len(vertices)
    
    # Cria mapeamento vértice -> índice
    vertice_para_indice = {v: i for i, v in enumerate(vertices)}
    
    # Inicializa matriz de distâncias
    dist = [[float('inf')] * n for _ in range(n)]
    
    for i in range(n):
        for j in range(n):
            if i == j:
                dist[i][j] = 0
            else:
                u = vertices[i]
                v = vertices[j]
                dist[i][j] = grafo.peso(u, v)
    
    # Algoritmo de Floyd-Warshall
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if dist[i][k] != float('inf') and dist[k][j] != float('inf'):
                    nova_dist = dist[i][k] + dist[k][j]
                    if nova_dist < dist[i][j]:
                        dist[i][j] = nova_dist
    
    return dist

def main():
    if len(sys.argv) != 2:
        print(f"Uso: {sys.argv[0]} <arquivo_grafo>")
        sys.exit(1)
    
    arquivo = sys.argv[1]
    grafo = Grafo(arquivo)
    
    matriz_dist = floyd_warshall(grafo)
    vertices = grafo.get_vertices()
    
    for i, vertice in enumerate(vertices):
        linha = f"{vertice}:"
        
        for j in range(len(vertices)):
            if j > 0:
                linha += ","
            
            if matriz_dist[i][j] == float('inf'):
                linha += "inf"
            else:
                # Remove decimais desnecessários
                if matriz_dist[i][j] == int(matriz_dist[i][j]):
                    linha += str(int(matriz_dist[i][j]))
                else:
                    linha += str(matriz_dist[i][j])
        
        print(linha)

if __name__ == "__main__":
    main()
