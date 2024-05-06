class Solution:
    def makesquare(self, matchsticks: list[int]) -> bool:
        totalLen = sum(matchsticks)
        if totalLen % 4:
            return False
        tLen = totalLen // 4

        dp = [-1] * (1 << len(matchsticks))
        dp[0] = 0
        for s in range(1,len(dp)):
            for k,v in enumerate(matchsticks):
                if s & (1 << k):
                    continue
                s1 = s & ~(1 << k)
                if dp[s1] >= 0 and dp[s1] + v <= len:
                    dp[s] = (dp[s1] + v) % tLen
                    break
        return dp[-1] == 0
