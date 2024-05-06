from pprint import pprint
class Solution(object): #随手写个暴力解法
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        line = len(grid[0])
        row = len(grid)
        for t in range(row-2,-1,-1):
            grid[t][line-1] += grid[t+1][line-1]
        for s in range(line-2,-1,-1):
            grid[row-1][s] += grid[row-1][s+1]
        for i in range(row - 2, -1, -1):
            for j in range(line - 2, -1, -1):
                grid[i][j] += min(grid[i][j+1],grid[i+1][j])
        return grid[0][0]


t = Solution()
pprint(t.minPathSum([[1,3,1],[1,5,1],[4,2,1]]))

