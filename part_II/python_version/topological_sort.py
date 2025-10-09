class Aresta:
    def __init__(self, origem, destino, peso=0):
        self.origem = origem
        self.destino = destino
        self.peso = peso

class Grafo:
    def __init__(self, dirigido=False):
        self.vertices = []
        self.arestas = []
        self.rotulos = {}
        self.dirigido = dirigido
    
    @classmethod
    def carregar_do_arquivo(cls, nome_arquivo):
        """Método para carregar grafo de arquivo (implementar conforme seu formato)"""
        grafo = cls()
        try:
            with open(nome_arquivo, 'r') as arquivo:
                # Implemente a leitura do arquivo aqui
                # Exemplo básico:
                for linha in arquivo:
                    # Processar cada linha do arquivo
                    pass
        except FileNotFoundError:
            raise Exception(f"Arquivo {nome_arquivo} não encontrado")
        return grafo
    
    def kruskal(self):
        """Implementação do algoritmo de Kruskal"""
        peso_total = 0.0
        mst = []  # Minimum Spanning Tree
        # Implemente o algoritmo aqui
        return peso_total, mst
    
    def componentes_fortemente_conexas(self):
        """Implementação para encontrar componentes fortemente conexas"""
        componentes = []
        # Implemente o algoritmo aqui (Kosaraju ou Tarjan)
        return componentes
    
    def ordenacao_topologica(self):
        """Implementação da ordenação topológica"""
        ordem = []
        # Implemente o algoritmo aqui
        return ordem
    
    def get_rotulo(self, vertice):
        """Retorna o rótulo do vértice"""
        return self.rotulos.get(vertice, str(vertice))
    
    # Adicione outros métodos necessários...
