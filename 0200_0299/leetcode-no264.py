from typing import *
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        p2 = p3 = p5 = 1
        dp = [0,1]
        for i in range(2,n+1):
            dp.append((min(dp[p2]*2,dp[p3]*3,dp[p5]*5)))
            if dp[i] == dp[p2]*2:
                p2 += 1
            if dp[i] == dp[p3]*3:
                p3 += 1
            if dp[i] == dp[p5]*5:
                p5 += 1

        return dp[n]
t = Solution()
print(t.nthUglyNumber(10))



