import math
from typing import Dict, List, Set, Optional

class Grafo:
    def __init__(self, arquivo: str = None):
        self.vertices: Dict[int, str] = {}  # índice -> rótulo
        self.adjacencias: Dict[int, Dict[int, float]] = {}  # u -> {v: peso}
        self.num_vertices = 0
        self.num_arestas = 0
        
        if arquivo:
            self.ler(arquivo)
    
    def qtd_vertices(self) -> int:
        return self.num_vertices
    
    def qtd_arestas(self) -> int:
        return self.num_arestas
    
    def grau(self, v: int) -> int:
        return len(self.adjacencias.get(v, {}))
    
    def rotulo(self, v: int) -> str:
        return self.vertices.get(v, "")
    
    def vizinhos(self, v: int) -> List[int]:
        viz = list(self.adjacencias.get(v, {}).keys())
        viz.sort()
        return viz
    
    def ha_aresta(self, u: int, v: int) -> bool:
        return u in self.adjacencias and v in self.adjacencias[u]
    
    def peso(self, u: int, v: int) -> float:
        if self.ha_aresta(u, v):
            return self.adjacencias[u][v]
        return float('inf')
    
    def ler(self, arquivo: str):
        try:
            with open(arquivo, 'r', encoding='utf-8') as file:
                linhas = file.readlines()
        except Exception as e:
            print(f"Erro ao abrir arquivo: {arquivo}")
            return
        
        # Lê primeira linha (*vertices n)
        primeira_linha = linhas[0].strip()
        partes = primeira_linha.split()
        if len(partes) >= 2 and partes[0] == "*vertices":
            self.num_vertices = int(partes[1])
        else:
            print("Formato de arquivo inválido")
            return
        
        # Lê rótulos dos vértices
        idx_linha = 1
        for i in range(self.num_vertices):
            if idx_linha >= len(linhas):
                break
                
            linha = linhas[idx_linha].strip()
            idx_linha += 1
            
            if not linha:
                continue
                
            partes = linha.split()
            if partes:
                indice = int(partes[0])
                rotulo_vertex = partes[1] if len(partes) > 1 else str(indice)
                self.vertices[indice] = rotulo_vertex
        
        # Procura por *edges
        while idx_linha < len(linhas):
            linha = linhas[idx_linha].strip()
            idx_linha += 1
            if linha.find("*edges") != -1:
                break
        
        # Lê arestas
        arestas_unicas: Set[str] = set()
        
        while idx_linha < len(linhas):
            linha = linhas[idx_linha].strip()
            idx_linha += 1
            
            if not linha:
                continue
                
            partes = linha.split()
            if len(partes) >= 3:
                u = int(partes[0])
                v = int(partes[1])
                peso_aresta = float(partes[2])
                
                # Grafo não-dirigido: adiciona em ambas as direções
                if u not in self.adjacencias:
                    self.adjacencias[u] = {}
                if v not in self.adjacencias:
                    self.adjacencias[v] = {}
                    
                self.adjacencias[u][v] = peso_aresta
                self.adjacencias[v][u] = peso_aresta
                
                # Conta aresta única
                aresta_id = f"{min(u, v)}-{max(u, v)}"
                arestas_unicas.add(aresta_id)
        
        self.num_arestas = len(arestas_unicas)
    
    def get_vertices(self) -> List[int]:
        vertices = list(self.vertices.keys())
        vertices.sort()
        return vertices
