from pprint import pprint
class Solution:
    def getMaximumGold(self, grid: list[list[int]]) -> int:
        rows = len(grid)
        cols = len(grid[0])
        res = []
        def dfs(currentx,currenty,path,total):
            k = 1
            if currentx > 0 and grid[currenty][currentx-1] and not [currentx-1,currenty] in path:
                dfs(currentx-1,currenty,path+[[currentx-1,currenty]],total+grid[currenty][currentx-1])
                k = 0

            if currentx < cols-1 and grid[currenty][currentx+1] and not [currentx+1,currenty] in path:
                dfs(currentx+1,currenty,path+[[currentx+1,currenty]],total+grid[currenty][currentx+1])
                k = 0

            if currenty > 0 and grid[currenty-1][currentx] and not [currentx,currenty-1] in path:
                dfs(currentx,currenty-1,path+[[currentx,currenty-1]],total+grid[currenty-1][currentx])
                k = 0

            if currenty < rows-1 and grid[currenty+1][currentx] and not [currentx,currenty+1] in path:
                dfs(currentx,currenty+1,path+[[currentx,currenty+1]],total+grid[currenty+1][currentx])
                k = 0

            if k:
                res.append(total)
        # dfs(1,3[[1,3]])
        for i in range(rows):
            for j in range(cols):
                # print(i,j)
                if grid[i][j]:
                    dfs(j,i,[[j,i]],grid[i][j])
        if res:
            return max(res)
        return -1


t = Solution()
print(t.getMaximumGold([[0,6,0],[5,8,7],[0,9,0]]))
print(t.getMaximumGold([[1,0,7],[2,0,6],[3,4,5],[0,3,0],[9,0,20]]))
