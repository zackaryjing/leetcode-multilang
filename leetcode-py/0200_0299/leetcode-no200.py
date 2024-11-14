class Solution:
    def numIslands(self, grid: list[list[str]]) -> int:
        m = len(grid)
        n = len(grid[0])
        def inarea(i,j):
            if 0 <= i < m and 0 <= j < n:
                return True
            return False
        def dfs(x,y):
            if inarea(x,y) and grid[x][y] == "1":
                grid[x][y] = "2"
                dfs(x-1,y)
                dfs(x,y-1)
                dfs(x+1,y)
                dfs(x,y+1)
                return 1
            return 0
        res = 0
        for k in range(m):
            for l in range(n):
                res += dfs(k,l)
        return res
grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
grid2 = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
t = Solution()
print(t.numIslands(grid2))

