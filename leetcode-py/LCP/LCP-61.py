from typing import *
class Solution:
    def temperatureTrend(self, temperatureA: List[int], temperatureB: List[int]) -> int:
        n = len(temperatureA)
        trendA = []
        trendB = []
        for i in range(1,n):
            if temperatureA[i] > temperatureA[i-1]:
                trendA.append(1)
            elif temperatureA[i] == temperatureA[i-1]:
                trendA.append(2)
            else:
                trendA.append(0)
            if temperatureB[i] > temperatureB[i - 1]:
                trendB.append(1)
            elif temperatureB[i] == temperatureB[i - 1]:
                trendB.append(2)
            else:
                trendB.append(0)
        # print(trendA)
        # print(trendB)
        maxum = 0
        ans = 0
        for j in range(n-1):
            if trendB[j] == trendA[j]:
                ans += 1
            else:
                if ans > maxum:
                    maxum = ans
                ans = 0
        if ans > maxum:
            maxum = ans
        return maxum

t = Solution()
print(t.temperatureTrend([5,10,16,-6,15,11,3],[16,22,23,23,25,3,-16]))
print(t.temperatureTrend([21,18,18,18,31],[34,32,16,16,17]))
