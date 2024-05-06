class Solution:
    def findPaths(self, m: int, n: int, maxMove: int, startRow: int, startColumn: int) -> int:
        mod = 1000000007
        directions = [[-1,0],[1,0],[0,-1],[0,1]]
        outCounts = 0
        dp = [[[0] * n for _ in range(m)] for _ in range(maxMove+1)]
        dp[0][startRow][startColumn] = 1
        for i in range(maxMove):
            for j in range(m):
                for k in range(n):
                    count = dp[i][j][k]
                    for direction in directions:
                        j1 = j + direction[0]
                        k1 = k + direction[1]
                        if j1 >= 0 and j1 < m and k1 >= 0 and k1 < n:
                            dp[i+1][j1][k1] = (dp[i+1][j1][k1] + count) % mod
                        else:
                            outCounts = (outCounts + count) % mod
        return outCounts