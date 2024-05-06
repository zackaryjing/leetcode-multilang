class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        word2 = " " + word2
        word1 = " " + word1
        n1 = len(word1)
        n2 = len(word2)
        dp = [[0] * n2 for _ in range(n1)]
        for i in range(1,n1):
            for j in range(1,n2):
                if word1[i] == word2[j]:
                    dp[i][j] = dp[i-1][j-1] + 1
                else:
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1])
        print(dp[-1][-1],"SD")
        return n1 + n2 - 2 * dp[-1][-1] - 2

t = Solution()
print(t.minDistance("bdcaba","abcbdab"))
print(t.minDistance("abcde","ace"))
print(t.minDistance("leetcode","etco"))
