import pprint
import copy
class Solution2:
    def numDistinct(self, s: str, t: str) -> int:
        n = len(s)
        m = len(t)
        dp = [[0] * (m + 1) for _ in range(n + 1)]
        for k in range(n+1):
            dp[k][0] = 1
            
        for j in range(1,m+1):
            for i in range(j,n+1):
                # print(i,j,s[i-1], t[j-1])
                if s[i-1] == t[j-1]:
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j]
                else:
                    dp[i][j] = dp[i-1][j]
        pprint.pprint(dp)
        return dp[-1][-1]


class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        n = len(s)
        m = len(t)
        dp1 = [1] * (n + 1)
        dp2 = [0] * (n + 1)
        for j in range(1,m+1):
            # print(dp1)
            for i in range(j,n+1):
                # print(i,j,s[i-1], t[j-1])
                if s[i-1] == t[j-1]:
                    dp2[i] = dp2[i-1] + dp1[i-1]
                else:
                    dp2[i] = dp2[i-1]
            dp1 = copy.copy(dp2)
            dp2 = [0] * (n + 1)
        return dp1[-1]


t = Solution()
pprint.pprint(t.numDistinct("rabbbit","rabbit"))
pprint.pprint(t.numDistinct("aabbbaa","abba"))
pprint.pprint(t.numDistinct("rrarabbit","rabbit"))
t = Solution2()
pprint.pprint(t.numDistinct("rabbbit","rabbit"))
pprint.pprint(t.numDistinct("aabbbaa","abba"))
pprint.pprint(t.numDistinct("rrarabbit","rabbit"))
