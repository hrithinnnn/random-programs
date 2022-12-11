class graph:
    def __init__(self,n):
        self.v=n
        self.graph=[]
    def add_edge(self,u,v,w):
        self.graph.append([u,v,w])

vertices=[]
edges=[]

g=graph(6)
g.add_edge(0, 1, 4)
g.add_edge(0, 2, 4)
g.add_edge(1, 2, 2)
g.add_edge(1, 0, 4)
g.add_edge(2, 0, 4)
g.add_edge(2, 1, 2)
g.add_edge(2, 3, 3)
g.add_edge(2, 5, 2)
g.add_edge(2, 4, 4)
g.add_edge(3, 2, 3)
g.add_edge(3, 4, 3)
g.add_edge(4, 2, 4)
g.add_edge(4, 3, 3)
g.add_edge(5, 2, 2)
g.add_edge(5, 4, 3)
g.graph = sorted(g.graph, key=lambda item: item[2])
#print(g.graph)
#print(g)
for i in g.graph:
    if i[0] not in vertices or i[1] not in vertices:
        if i[0] not in vertices:
            vertices.append(i[0])
        if i[1] not in vertices:
            vertices.append(i[1])
        edges.append(i)
print(edges)

