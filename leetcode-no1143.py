class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        text1 = " " + text1
        text2 = " " + text2
        n1 = len(text1)
        n2 = len(text2)
        dp = [[0]*n1 for _ in range(n2)]
        for i in range(1,n2):
            for j in range(1,n1):
                # print(i,j)
                if text1[j] == text2[i]:
                    # print(text1[j],text2[i],"ADSF")
                    dp[i][j] = dp[i-1][j-1] + 1
                else:
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1])
        # print(dp)
        return dp[-1][-1]

t = Solution()
print(t.longestCommonSubsequence("bdcaba","abcbdab"))
print(t.longestCommonSubsequence("abcde","ace"))
