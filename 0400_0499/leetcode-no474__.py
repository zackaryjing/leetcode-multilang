from typing import *
from pprint import pprint
class Solution:
    def findMaxForm(self, strs: List[str], m: int, n: int) -> int:
        length = len(strs)
        dp = [[[0]*(n+1) for i in range(m+1)] for j in range(length+1)]
        strs.insert(0,"")
        zeros = 0
        ones = 0
        for i in range(length+1):
            for char in strs[i]:
                if char == "1": ones += 1
                else: zeros += 1
            for j in range(m+1):
                for k in range(n+1):
                    dp[i][j][k] = dp[i-1][j][k]
                    if j >= zeros and k >= ones:
                        dp[i][j][k] = max(dp[i][j][k],dp[i-1][j-zeros][k-ones]+1)
        pprint(dp)
        return dp[length][m][n]


t = Solution()
print(t.findMaxForm(["10", "0001", "111001", "1", "0"],5,3))




