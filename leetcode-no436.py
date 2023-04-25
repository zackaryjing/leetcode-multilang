class Solution2:
    def findRightInterval(self, intervals: list[list[int]]) -> list[int]:
        res = []
        lth1 = len(intervals)
        for i in range(lth1):
            h = float("inf")
            z = lth1+1
            for j in range(lth1):
                if intervals[i][1] <= intervals[j][0]:
                    if intervals[j][0] < h:
                        z = j
                        h = intervals[j][0]
            if z == lth1+1:
                res.append(-1)
            else:
                res.append(z)
        return res
"""TLE"""
class Solution:
    def findRightInterval(self, intervals: list[list[int]]) -> list[int]:
        rights = [i[1] for i in intervals]
        lefts = [[intervals[i][0],i] for i in range(len(intervals))]
        order = sorted(lefts)
        res = []
        for j in rights:
            k = 1
            for t in order:
                if t[0] >= j:
                    res.append(t[1])
                    k = 0
                    break
            if k:
                res.append(-1)
        return res


t = Solution()
print(t.findRightInterval([[1,2]]))
print(t.findRightInterval([[3,4],[2,3],[1,2]]))
print(t.findRightInterval([[1,4],[2,3],[3,4]]))


