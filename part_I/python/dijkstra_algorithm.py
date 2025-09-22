import heapq
import math
from typing import Dict, List, Tuple
import sys

# Assumindo que você tem uma classe Grafo equivalente
class Grafo:
    def __init__(self, arquivo: str):
        # Implementação da leitura do arquivo
        self.vertices = {}
        self._ler_arquivo(arquivo)
    
    def _ler_arquivo(self, arquivo: str):
        # Implemente a leitura do arquivo conforme sua necessidade
        with open(arquivo, 'r') as f:
            # Exemplo simples - adapte conforme seu formato
            lines = f.readlines()
            # Lógica para parse do arquivo
            pass
    
    def qtdVertices(self) -> int:
        return len(self.vertices)
    
    def vizinhos(self, u: int) -> List[int]:
        # Retorna lista de vértices vizinhos ao vértice u
        if u in self.vertices:
            return list(self.vertices[u].keys())
        return []
    
    def peso(self, u: int, v: int) -> float:
        # Retorna o peso da aresta entre u e v
        if u in self.vertices and v in self.vertices[u]:
            return self.vertices[u][v]
        return math.inf

class Node:
    def __init__(self, v: int, dist: float):
        self.v = v
        self.dist = dist
    
    def __lt__(self, other):
        return self.dist < other.dist
    
    def __gt__(self, other):
        return self.dist > other.dist

def dijkstra(grafo: Grafo, s: int) -> Tuple[Dict[int, float], Dict[int, int]]:
    n = grafo.qtdVertices()
    dist = {}
    antecessor = {}
    
    # Inicializa distâncias
    for v in range(1, n + 1):
        dist[v] = math.inf
        antecessor[v] = -1
    dist[s] = 0
    
    # Min-heap
    pq = []
    heapq.heappush(pq, Node(s, 0))
    
    while pq:
        atual = heapq.heappop(pq)
        u = atual.v
        
        # Relaxamento
        for viz in grafo.vizinhos(u):
            peso = grafo.peso(u, viz)
            if dist[u] + peso < dist[viz]:
                dist[viz] = dist[u] + peso
                antecessor[viz] = u
                heapq.heappush(pq, Node(viz, dist[viz]))
    
    return dist, antecessor

def reconstruir_caminho(v: int, antecessor: Dict[int, int]) -> List[int]:
    caminho = []
    atual = v
    while atual != -1:
        caminho.append(atual)
        atual = antecessor[atual]
    caminho.reverse()
    return caminho

def main():
    if len(sys.argv) != 3:
        print(f"Uso: {sys.argv[0]} <arquivo_grafo> <vertice_inicial>")
        sys.exit(1)
    
    arquivo = sys.argv[1]
    s = int(sys.argv[2])
    
    grafo = Grafo(arquivo)
    dist, antecessor = dijkstra(grafo, s)
    
    # Imprime saída no formato pedido
    for v in range(1, grafo.qtdVertices() + 1):
        print(f"{v}: ", end="")
        
        caminho = reconstruir_caminho(v, antecessor)
        print(",".join(map(str, caminho)), end="")
        
        print("; d=", end="")
        if dist[v] == math.inf:
            print("inf", end="")
        else:
            print(f"{dist[v]}", end="")
        print()

if __name__ == "__main__":
    main()
