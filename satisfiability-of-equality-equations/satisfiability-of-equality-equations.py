class Solution:
    
    from typing import List, DefaultDict, Set
    from collections import defaultdict


    # Function that performs DFS.
    def dfs(self, x: str, y: str, adj: DefaultDict[str, set], visited: Set[int]) -> bool:

        # If x is neighbour of y return true.
        if x in adj[y]:
            return True

        # Otherwise check if x is the neighbour of any other neighbour of y.
        for child in adj[y]:

            if child not in visited:
                visited.add(child)

                # If x is neighbour of any neighbour of y return True.
                if self.dfs(x, child, adj, visited):
                    return True

        # If x is not found return False.
        return False

    
    def equationsPossible(self, equations: List[str]) -> bool:
        # Create an adjecency list.
        adj = defaultdict(set)

        for eqn in equations:

            x, op, y = eqn[0], eqn[1: 3], eqn[-1]

            # If any == comparator is found make and edge.
            if op == '==':
                adj[x].add(y)
                adj[y].add(x)

        for eqn in equations:

            x, op, y = eqn[0], eqn[1: 3], eqn[-1]

            # If an != is found check if x and y are equal or in the same component.
            if op == '!=':
                if x == y:
                    return False

                # If x is reachable from y return False.
                if self.dfs(x, y, adj, set()):
                    return False

        # Otherwise, return True.
        return True
