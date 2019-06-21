import sys

"""
Skeleton for dijkstra.py. Based on code originally written by Andrea Sigler.
Brought to you by wikinotes.ca.
"""

# Based on the original HeapNode class, only modified slightly
class HeapNode:
    def __init__(self, vertex, edge, value=sys.maxint):
        """
        Each heap node represents a vertex, has a value (i.e. the
        shortest distance between it and the set of found vertices),
        and points to an edge in the graph that corresponds to the
        value above.
        """
        self.vertex = vertex
        self.value = value
        self.edge = edge
        self.path = []

    def __repr__(self):
        return "(vertex: %d, val: %d, edge: %s)" % (self.vertex, self.value, self.edge)

# Helper class - not part of original
class Graph:
    def __init__(self, edges):
        self.edges = edges

    # Based on the original HeapSwap() method
    def swap_heap_elements(self, i, j):
        i_index = self.heap[i].vertex
        j_index = self.heap[j].vertex
        # Because swapping variables in python doesn't require temp vars <3
        self.pointers[i_index], self.pointers[j_index] = self.pointers[j_index], self.pointers[i_index]
        self.heap[i], self.heap[j] = self.heap[j], self.heap[i]

    # Implement this method
    def get_right_child(self, i):
        """
        Returns the index of the right child of an element in the heap
        (identified by its index)
        """
        pass

    # Implement this method
    def get_left_child(self, i):
        """
        Returns the index of the left child of an element in the heap.
        If there is no parent, returns None
        """
        pass

    # Implement this method
    def get_parent(self, i):
        """
        Returns the index of the parent of an element in the heap. The list
        is 0-indexed. If there is no parent, returns None
        """
        pass

    # Implement this method
    def heapify_up(self, i):
        """
        If the value at the index is smaller than the value of the parent,
        swap the two. Keeps going recursively.
        """
        pass

    # Helper method, not part of original
    def is_valid_index(self, i):
        if i < 0 or i >= len(self.heap):
            return False
        else:
            return True

    # Helper method, not part of original
    def get_min_child(self, i):
        right = self.get_right_child(i)
        left = self.get_left_child(i)
        if self.is_valid_index(left):
            left_value = self.heap[left].value
            if self.is_valid_index(right):
                right_value = self.heap[right].value
                return right if right_value < left_value else left
            else:
                # There only is a left child. Return the left child
                return left
        else:
            # No children
            return None

    # Implement this
    def heapify_down(self, i):
        """
        If the value at the index s greater than either of its children,
        swap as necessary. Keeps going recursively.
        """
        pass

    # Implement this
    def remove_heap_min(self):
        """
        Removes the minimum element of the heap (don't forget the change
        the pointer to it to None
        """
        pass

    # Implement this method
    def heap_insert(self, node):
        """
        Inserts a new element into the heap, respecting the min-heap
        property. May need an index parameter - or maybe not?
            No, it doesn't. Incidentally these heap methods would be more
        fitting as instance methods on a Heap class but whatever too late.
        """
        pass

    # Implement this method
    def decrease_value(self, i, new_value):
        """
        Changes the value of a node to the new value (which must be lower
        than the previous value), respecting the min-heap property etc.
        """
        pass

    # Based on the original MakeHeap() method
    def make_heap(self):
        """
        Initialises the heap by making a heap node for each vertex and
        inserting each heap node into the heap. Called in get_distances()
        """
        self.heap = []
        self.pointers = [] # set here because it's only used for the heap
        self.nodes = [] # keep track of them here because the heap is modified
        for i in xrange(self.num_nodes):
            node = HeapNode(i, self.cheap_edges[i], value=self.values[i])
            self.nodes.append(node)
            self.pointers.append(i)
            self.heap_insert(node)

    # Based on the original InitValues() method
    def init_values(self):
        """
        Initialises the values and cheap edges lists for the heap. Called
        in get_distances
        """
        # First initialise all the lists etc and calculate the number of nodes
        self.num_nodes = len(self.edges)
        self.distances = [sys.maxint] * self.num_nodes
        self.cheap_edges = [0] * self.num_nodes
        self.values = [0] * self.num_nodes

        for i in xrange(self.num_nodes):
            if i == self.start:
                self.values[i] = 0
            else:
                min_value = sys.maxint # sigh
                min_edge = []
                for edge in self.edges[self.start]:
                    if edge[1] == i:
                        # edge[2] is the value
                        if edge[2] < min_value:
                            min_value = edge[2]
                            min_edge = edge
                self.values[i] = min_value
                self.cheap_edges[i] = min_edge
        self.distances[self.start] = 0

    # Implement this method
    def decrement_adjacent_edges(self, node):
        """
        Checks all edges adjacent to the given vertex. For each edge that
        leads to a vertex found in the heap, we calculate the cost of
        reaching that vertex through the cheapest path from the starting
        vertex to the given vertex plus the new edge etc.
            If this value is less than the current value of the heap node,
        we decrease the value of the node and record the new cheap edge
        as the node's edge
        """
        pass

    # Implement this method
    def get_distances(self, start):
        """
        This is where you do the Dijkstra stuff.
        Gets the shortest path from the start node to every other.
        Returns a tuple of lists: the first is the list of the distances.
        The second list is a list of lists, each of which shows the path.
        """
        return ([], [])

# Only run this if called through `python dijkstra.py`
# That way you can test it more easily etc
if __name__ == '__main__':
    filename = sys.argv[1]
    start = int(sys.argv[2])
    f = open(filename)
    num_nodes = int(f.readline()) # Not actually necessary (see len(edges))
    # Back to using eval because linux is running an old version of Python...
    edges = eval(f.readline())
    f.close()

    # Create a Graph object with the given edges
    graph = Graph(edges)

    # Print out the distance of the shortest path to every vertex from start
    # Then, print out the paths taken
    # This returns a tuple - the distances, and the parents
    distances, paths = graph.get_distances(start)
    print distances
    for path in paths:
print path
