from typing import *
class Solution:
    def minAreaFreeRect(self, points: List[List[int]]) -> float:
        n = len(points)
        space = []
        maxum = float('inf')
        for i in range(n):
            for j in range(i+1,n):
                for k in range(j+1,n):
                    for p1,p2,p3 in [[points[i],points[j],points[k]],
                                     [points[j],points[i],points[k]],
                                     [points[k],points[j],points[i]]]:
                        # print(p1,p2,p3)
                        if (p2[1] - p1[1]) * (p3[1] - p1[1]) + (p2[0] - p1[0]) * (p3[0] - p1[0]) == 0:
                            if [p2[0] + p3[0] - p1[0],p2[1] + p3[1] - p1[1]] in points:
                                if (a:= abs((p2[1] - p1[1])*(p3[0] - p1[0])-(p3[1] - p1[1])*(p2[0] - p1[0]))) < maxum:
                                    maxum = a
        return maxum if maxum != float('inf') else 0

t = Solution()
print(t.minAreaFreeRect([[0,1],[2,1],[1,1],[1,0],[2,0]]))





