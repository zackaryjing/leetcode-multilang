class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        #本来还是想用公式的，结果发现写不出来
        #只好动态规划了
        if obstacleGrid == [[0]]:
            return 1
        line = len(obstacleGrid[0])
        row = len(obstacleGrid)
        k,g = 1,1
        if obstacleGrid[row - 1][line - 1] == 1:
            return 0
        for t in range(row - 2, -1, -1):
            if not obstacleGrid[t][line - 1] == 1 and g:
                obstacleGrid[t][line - 1] += 1
            else:
                obstacleGrid[t][line - 1] = 0
                g = 0
        for s in range(line - 2, -1, -1):
            if not obstacleGrid[row - 1][s] == 1 and k:
                obstacleGrid[row - 1][s] += 1
            else:
                obstacleGrid[row - 1][s] = 0
                k = 0
        for i in range(row - 2, -1, -1):
            for j in range(line - 2, -1, -1):
                if not obstacleGrid[i][j] == 1:
                    obstacleGrid[i][j] += obstacleGrid[i][j + 1]+obstacleGrid[i + 1][j]
                else:
                    obstacleGrid[i][j] = 0
        return obstacleGrid

t = Solution()
print(t.uniquePathsWithObstacles([[0,0,0],[0,1,0],[0,0,0]]))
for i in t.uniquePathsWithObstacles([[0,0,0],[0,1,0],[0,0,0]]):
    for j in i:
        print("% 9d" %j,end="")
    print()
for i in t.uniquePathsWithObstacles([[0,0,0,0,0,1,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,1,0,0,0,0,1,0,1,0,1,0,0],[1,0,0,0,0,0,1,0,0,0,0,0,1,0,1,1,0,1],[0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0],[0,0,0,0,0,1,0,0,0,0,1,1,0,1,0,0,0,0],[1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0],[0,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0],[1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,1,0,0],[0,0,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0],[0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0],[0,0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,0,1],[0,1,0,1,0,1,0,0,0,0,0,0,0,1,0,0,0,0],[0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1],[1,0,1,1,0,0,0,0,0,0,1,0,1,0,0,0,1,0],[0,0,0,1,0,0,0,0,1,1,1,0,0,1,0,1,1,0],[0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0],[0,1,1,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0],[0,0,0,0,0,0,1,0,1,0,0,1,0,1,1,1,0,0],[0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,1],[0,1,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0],[1,0,0,1,0,1,0,0,1,0,0,0,0,0,0,0,0,0],[0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0],[0,1,0,0,0,0,0,1,0,0,0,0,0,0,1,1,1,0],[1,0,1,0,1,0,0,0,0,0,0,1,1,0,0,0,0,1],[1,0,0,0,0,0,1,1,0,0,0,1,0,0,0,0,0,0]]):
    for j in i:
        print("% 9d" %j,end="")
    print()