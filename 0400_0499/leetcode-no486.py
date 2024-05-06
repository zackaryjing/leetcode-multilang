from typing import *
from pprint import pprint
from pprint import pp
class Solution:
    def PredictTheWinner(self, nums: List[int]) -> bool:
        n = len(nums)
        dp = [[0]*n for _ in range(n)]
        for i in range(n-1,-1,-1):
            for j in range(i,n):
                if j == i:
                    dp[i][j] = nums[i]
                else:
                    dp[i][j] = max(nums[i] - dp[i+1][j],nums[j] - dp[i][j-1])
        # pp(dp)
        return dp[0][n-1] >= 0

t = Solution()
print(t.PredictTheWinner([1,5,2]))
print(t.PredictTheWinner([1,5,233,7]))
