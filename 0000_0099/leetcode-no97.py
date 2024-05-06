class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        s1len = len(s1)
        s2len = len(s2)
        s3len = len(s3)
        if not (s1len + s2len) == s3len:
            return False
        if s1len == 0:
            if not s2 == s3:
                return False
            else:
                return True
        if s2len == 0:
            if not s1 == s3:
                return False
            else:
                return True
        dp = [[False] * (s2len+1) for _ in range(s1len+1)]
        dp[0][0] = True
        for i in range(1,s1len+1):
            if s1[i-1] == s3[i-1]:
                dp[i][0] = dp[i-1][0] and True
        for j in range(1,s2len+1):
            if s2[j-1] == s3[j-1]:
                dp[0][j] = dp[0][j-1] and True
        for k in range(1,s1len+1):
            for g in range(1,s2len+1):
                dp[k][g] = ((dp[k-1][g] and (s1[k-1] == s3[k+g-1])) or (dp[k][g-1] and (s2[g-1] == s3[k+g-1])))
        return dp[-1][-1]

t = Solution()
# a = t.isInterleave("aabcc","dbbca","aadbbcbcac")
# a = t.isInterleave("","b","b")
# a = t.isInterleave("db","b","cbb")
a = t.isInterleave("aabcc","dbbca","aadbbbaccc")
print(a)
for k in a:
    print(k)