class Solution:
    
    def dfs(self, m: int, n: int, matrix1: List[List[int]], matrix2: List[List[int]], i: int, j: int, good: List[int]):
    
        # Base case.
        if i < 0  or i >= m or j < 0 or j >= n or matrix2[i][j] != 1:
            return

        # Mark cell as visited.
        matrix2[i][j] = -1

        # Check for 1 in matrix1.
        if matrix1[i][j] == 0:
            good[0] = 0

        # Travel in 4 directions recursively.
        self.dfs(m, n, matrix1, matrix2, i - 1, j, good)
        self.dfs(m, n, matrix1, matrix2, i + 1, j, good)
        self.dfs(m, n, matrix1, matrix2, i, j + 1, good)
        self.dfs(m, n, matrix1, matrix2, i, j - 1, good)


    
    def countSubIslands(self, matrix1: List[List[int]], matrix2: List[List[int]]) -> int:
        m = len(matrix1)
        n = len(matrix1[0])
        # To store number of good islands.
        ans = 0

        for i in range(0,m):
            for j in range(0,n):

                # Check in matrix2.
                if matrix2[i][j] == 1:

                    # To check for good island.
                    good = [1]

                    # Call dfs function.
                    self.dfs(m, n, matrix1, matrix2, i, j, good)

                    # Check if good island.
                    if good[0] == 1:
                        ans += 1

        return ans

        