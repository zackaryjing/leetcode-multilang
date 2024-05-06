from pprint import pprint
class Solution:
    def knightProbability(self, n: int, k: int, row: int, column: int) -> float:
        dp = [[[0] * n for _ in range(n)] for t in range(k+1)]
        dp[0][row][column] = 1
        directions = [[-1,-2],[-2,-1],[-1,2],[2,-1],[-2,1],[1,-2],[2,1],[1,2]]
        for i in range(1,k+1):
            for j in range(n):
                for m in range(n):
                    tmp = 0
                    for dx,dy in directions:
                        if 0 <= j+dx < n and 0 <= m + dy < n:
                            # print(dp)
                            tmp += dp[i-1][j+dx][m+dy]
                            # print(i, j, m, dx, dy, tmp,dp[i-1][j+dx][m+dy],j+dx,m+dy)
                    dp[i][j][m] = 1/8*(tmp)
        # pprint(dp)
        return sum(sum(dp[k],[]))

t = Solution()
# pprint(t.knightProbability(3,2,0,0))
pprint(t.knightProbability(3,1,1,1))










# t    =  [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
# data = [[0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
#         [0, 0, 0.25, 0, 0.25, 0.25, 0, 0.25, 0, 0],
#         [0, 0.25, 0, 0, 0.25, 0, 0.25, 0, 0.25, 0],
#         [0, 0.25, 0, 0, 0.25, 0, 0, 0, 0.25, 0],
#         [0.125, 0.125, 0, 0.125, 0, 0, 0, 0.25, 0, 0.125],
#         [0, 0.25, 0, 0, 0, 0, 0.25, 0, 0, 0],
#         [0, 0, 0.25, 0, 0, 0.25, 0, 0, 0, 0],
#         [0, 0.125, 0, 0, 0.25, 0, 0, 0, 0.125, 0],
#         [0, 0, 0.125, 0.125, 0, 0, 0, 0.125, 0, 0],
#         [0, 0, 0, 0, 0.25, 0, 0, 0, 0, 0]]
