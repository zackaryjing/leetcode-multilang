class Solution(object):
    def onesMinusZeros(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: List[List[int]]
        """

        rows = len(grid)
        cols = len(grid[0])
        result = [[0 for n in range(cols)] for m in range(rows)]
        for i in range(rows):
            for j in range(cols):
                result[i][j] = 2*sum(grid[i])+\
                    2*sum([t[j] for t in grid])-cols-rows
        return result

class Solution(object):
    def onesMinusZeros(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: List[List[int]]
        """
        rows = len(grid)
        cols = len(grid[0])
        middle = rows+cols
        rowsum = []
        colsum = [0] * cols
        for i in grid:
            rowsum.append(sum(i))
            for j in range(cols):
                colsum[j] += i[j]
        ans = [[None]*cols for t in range(rows)]
        for i in range(rows):
            for j in range(cols):
                ans[i][j] = 2*(rowsum[i]+colsum[j])-middle
        return ans



t = Solution()
print(t.onesMinusZeros([[0,1,1],[1,0,1],[0,0,1],[1,1,1]]))
print(t.onesMinusZeros([[0,1,1],[1,0,1],[0,0,1]]))
