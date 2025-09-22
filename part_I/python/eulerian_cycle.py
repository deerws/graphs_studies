import sys
from typing import List, Dict, Set
from collections import defaultdict, deque

# Assumindo que você tem uma classe Grafo equivalente
class Grafo:
    def __init__(self, arquivo: str):
        self.vertices = set()
        self.adjacencias = defaultdict(list)
        self._ler_arquivo(arquivo)
    
    def _ler_arquivo(self, arquivo: str):
        # Implemente a leitura do arquivo conforme sua necessidade
        try:
            with open(arquivo, 'r') as f:
                lines = f.readlines()
                # Exemplo de formato esperado (adaptar conforme seu arquivo):
                # v1 v2
                # v3 v4
                for line in lines:
                    line = line.strip()
                    if not line:
                        continue
                    partes = line.split()
                    if len(partes) >= 2:
                        v1, v2 = int(partes[0]), int(partes[1])
                        self.adicionar_aresta(v1, v2)
        except FileNotFoundError:
            print(f"Erro: Arquivo '{arquivo}' não encontrado.")
            sys.exit(1)
    
    def adicionar_aresta(self, u: int, v: int):
        self.vertices.add(u)
        self.vertices.add(v)
        self.adjacencias[u].append(v)
        self.adjacencias[v].append(u)
    
    def get_todos_vertices(self) -> List[int]:
        return sorted(list(self.vertices))
    
    def grau(self, v: int) -> int:
        return len(self.adjacencias[v]) if v in self.adjacencias else 0
    
    def vizinhos(self, v: int) -> List[int]:
        return self.adjacencias.get(v, [])
    
    def qtd_vertices(self) -> int:
        return len(self.vertices)

def tem_ciclo_euleriano(grafo: Grafo) -> bool:
    vertices = grafo.get_todos_vertices()
    
    # Verifica se todos os vértices têm grau par
    for v in vertices:
        if grafo.grau(v) % 2 != 0:
            return False
    
    # Verifica conectividade usando BFS/DFS
    if not vertices:
        return False
    
    visitados = set()
    pilha = [vertices[0]]
    
    while pilha:
        v = pilha.pop()
        
        if v in visitados:
            continue
        
        visitados.add(v)
        
        for vizinho in grafo.vizinhos(v):
            if vizinho not in visitados:
                pilha.append(vizinho)
    
    # Verifica se todos os vértices com grau > 0 foram visitados
    for v in vertices:
        if grafo.grau(v) > 0 and v not in visitados:
            return False
    
    return True

def encontrar_ciclo_euleriano(grafo: Grafo) -> List[int]:
    if not tem_ciclo_euleriano(grafo):
        return []
    
    # Cria cópia das adjacências para remover arestas
    adj_copy = defaultdict(list)
    vertices = grafo.get_todos_vertices()
    
    for v in vertices:
        adj_copy[v] = grafo.vizinhos(v).copy()
    
    # Encontra vértice inicial (qualquer um com grau > 0)
    inicio = -1
    for v in vertices:
        if adj_copy[v]:
            inicio = v
            break
    
    if inicio == -1:
        return []
    
    pilha = [inicio]
    ciclo = []
    
    while pilha:
        v = pilha[-1]
        
        if adj_copy[v]:
            # Pega próximo vizinho
            u = adj_copy[v].pop()
            
            # Remove aresta u-v também
            if v in adj_copy[u]:
                adj_copy[u].remove(v)
            
            pilha.append(u)
        else:
            # Não há mais arestas, adiciona ao ciclo
            ciclo.append(pilha.pop())
    
    ciclo.reverse()
    return ciclo

def main():
    if len(sys.argv) != 2:
        print(f"Uso: {sys.argv[0]} <arquivo_grafo>")
        sys.exit(1)
    
    arquivo = sys.argv[1]
    
    try:
        grafo = Grafo(arquivo)
    except Exception as e:
        print(f"Erro ao carregar o grafo: {e}")
        sys.exit(1)
    
    ciclo = encontrar_ciclo_euleriano(grafo)
    
    if not ciclo:
        print("0")
    else:
        print("1")
        # Imprime o ciclo sem repetir o último vértice (que é igual ao primeiro)
        ciclo_str = ",".join(map(str, ciclo[:-1]))
        print(ciclo_str)

if __name__ == "__main__":
    main()
