"""
Dijkstra's algorithm
"""
from collections import defaultdict


class Graph:
    nodes = set()
    edges = defaultdict(list)
    distances = dict()

    def add_edge(self, a, b, distance):
        self.nodes.add(a)
        self.nodes.add(b)
        self.edges[a].append(b)
        self.edges[b].append(a)
        self.distances[(a, b)] = distance
        self.distances[(b, a)] = distance


def dijkstra(graph, source):
    dist = dict()
    prev = dict()
    dist[source] = 0

    nodes = g.nodes.copy()
    titleline = ' '.join(sorted(nodes - set([source])))
    print(r'\begin{tabular}{cc' + 'c' * len(nodes) + '}')
    print('\t' +
          'step & visited & ' + titleline.strip().replace(
              ' ', ' & ')
          + r'\\\hline')

    for node in nodes:
        if not node == source:
            dist[node] = g.distances.get((node, source), 99999)
            prev[node] = source if dist[node] < 99999 else None

    while nodes:
        u = min(nodes)
        nodes.remove(u)

        for neighbour in g.edges[u]:
            alt = dist[u] + g.distances[(u, neighbour)]
            if alt < dist[neighbour]:
                dist[neighbour] = alt
                prev[neighbour] = u

        visited = sorted(g.nodes - nodes)
        step = len(visited)
        table = ''
        for node in sorted(g.nodes - set([source])):
            if prev[node]:
                table += '{},{} & '.format(
                    dist[node], prev[node])
            else:
                table += '{} & '.format(dist[node])
        table = table.replace('99999', r'$\inf$')
        print('\t{} & {} & '.format(step, ''.join(visited))
              + table + r'\\')

    print(r'\end{tabular}')
    return (dist, prev)


if __name__ == '__main__':
    g = Graph()
    g.add_edge('t', 'u', 2)
    g.add_edge('t', 'v', 4)
    g.add_edge('t', 'y', 7)
    g.add_edge('u', 'v', 3)
    g.add_edge('u', 'w', 3)
    g.add_edge('v', 'w', 3)
    g.add_edge('v', 'x', 3)
    g.add_edge('v', 'y', 8)
    g.add_edge('w', 'x', 6)
    g.add_edge('x', 'y', 6)
    g.add_edge('x', 'z', 8)
    g.add_edge('y', 'z', 12)

    print(r'\subsection{from x}')
    dijkstra(g, 'x')
    print(r'\subsection{from t}')
    dijkstra(g, 't')
    print(r'\subsection{from v}')
    dijkstra(g, 'v')