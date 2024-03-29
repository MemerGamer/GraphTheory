class Prufer:
    def __init__(self, number_of_nodes):
        """
        Constructor for the Prufer class.

        :param number_of_nodes: The number of nodes in the tree.
        """
        self.number_of_nodes = number_of_nodes
        self.adjacency_list = [[] for _ in range(number_of_nodes + 1)]
        self.prufer_sequence = []
        self.decoded_edges = []

    def add_edge_directed(self, first_node, second_node):
        """
        Add a directed edge to the tree.

        :param first_node: The source node of the edge.
        :param second_node: The destination node of the edge.
        """
        self.adjacency_list[first_node].append(second_node)

    def add_edge_nondirected(self, first_node, second_node):
        """
        Add a nondirected edge to the tree.

        :param first_node: The first node of the edge.
        :param second_node: The second node of the edge.
        """
        self.adjacency_list[first_node].append(second_node)
        self.adjacency_list[second_node].append(first_node)

    def encode_tree(self):
        """
        Encode the tree into a Prufer sequence.

        :return: The Prufer sequence as a list.
        """
        leafs = set()
        degree = [0] * (self.number_of_nodes + 1)
        is_leaf_cut = [False] * (self.number_of_nodes + 1)
        prufer_sequence = []

        for current_node in range(1, self.number_of_nodes + 1):
            degree[current_node] = len(self.adjacency_list[current_node])
            if degree[current_node] == 1:
                leafs.add(current_node)

        for _ in range(self.number_of_nodes - 2):
            if leafs:
                leaf = min(leafs)
                leafs.remove(leaf)
                is_leaf_cut[leaf] = True

                origin_of_current_node = None

                for current_neighbour in self.adjacency_list[leaf]:
                    if not is_leaf_cut[current_neighbour]:
                        origin_of_current_node = current_neighbour
                        break

                prufer_sequence.append(origin_of_current_node)
                degree[origin_of_current_node] -= 1
                if degree[origin_of_current_node] == 1:
                    leafs.add(origin_of_current_node)
            else:
                break

        self.prufer_sequence = prufer_sequence
        return prufer_sequence

    def decode_prufer_sequence(self):
        """
        Decode a Prufer sequence into the corresponding tree edges.

        :return: The decoded tree edges as a list of tuples.
        """
        degree = [1] * (self.number_of_nodes + 2)

        for node in self.prufer_sequence:
            degree[node] += 1

        leaves = set()
        for i in range(1, self.number_of_nodes + 2):
            if degree[i] == 1:
                leaves.add(i)

        edges = []

        for origin_of_current_node in self.prufer_sequence:
            leaf = min(leaves)
            leaves.remove(leaf)
            edges.append((origin_of_current_node, leaf))
            degree[origin_of_current_node] -= 1
            if degree[origin_of_current_node] == 1:
                leaves.add(origin_of_current_node)

        leaf1 = min(leaves)
        leaves.remove(leaf1)
        leaf2 = min(leaves)
        edges.append((leaf1, leaf2))

        self.decoded_edges = edges
        return edges
