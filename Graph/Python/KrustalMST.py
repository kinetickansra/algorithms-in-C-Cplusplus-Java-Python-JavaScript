"""Krustal's algorithm for MST:
KRUSKAL(G):
1 A = ∅
2 foreach v ∈ G.V:
3    MAKE-SET(v)
4 foreach (u, v) in G.E ordered by weight(u, v), increasing:
5    if FIND-SET(u) ≠ FIND-SET(v):
6       A = A ∪ {(u, v)}
7       UNION(u, v)
8 return A
"""


from collections import defaultdict 
  
class Graph: 
    def __init__(self, vertices): 
        self.V = vertices 
        self.graph = []
   
    def add_edge(self,u,v,w):
        """add edge to graph"""
        self.graph.append([u,v,w]) 
  
    def find(self, parent, i):
        """implementation of find data-structure"""
        if parent[i] == i: 
            return i 
        return self.find(parent, parent[i]) 
  
    def union(self, parent, rank, v1, v2):
        """to find union of x and y"""
        root1 = self.find(parent, v1) 
        root2 = self.find(parent, v2) 
        if rank[root1] < rank[root2]: 
            parent[root1] = root2 
        elif rank[root1] > rank[root2]: 
            parent[root2] = root1 
        else : 
            parent[root2] = root1 
            rank[root1] += 1

    def krustal(self):
        result =[]
        i = 0 # variable for sorted edges 
        e = 0 # result[] 
        
        # sort all edges in non-decreasing order
        self.graph =  sorted(self.graph,key=lambda item: item[2]) 
        parent = [] ; rank = [] 
        # Create V subsets with single elements 
        for vertex in range(self.V): 
            parent.append(vertex) 
            rank.append(0)
       
        while e < self.V -1 : 
            u,v,w =  self.graph[i] 
            i = i + 1
            x = self.find(parent, u) 
            y = self.find(parent ,v) 
            # if edge doesn't conatain cycle
            if x != y: 
                e = e + 1     
                result.append([u,v,w]) 
                self.union(parent, rank, x, y)             
  
        print("MST:")
        for u,v,weight  in result: 
            print("{} -- {} -> {}".format(u,v,weight)) 

g = Graph(4) 
g.add_edge(0, 1, 10) 
g.add_edge(0, 2, 6) 
g.add_edge(0, 3, 5) 
g.add_edge(1, 3, 15) 
g.add_edge(2, 3, 4) 
g.krustal() 
