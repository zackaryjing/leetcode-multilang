class Solution2:
    def eraseOverlapIntervals(self, intervals: list[list[int]]) -> int:
        n = len(intervals)
        res = [1] * n
        intervals.sort()
        for i in range(1,n):
            res[i] = max([res[t] for t in range(i) if intervals[t][1] <= intervals[i][0]],default=0) + 1
        # print(res)
        return n-max(res)

class Solution:
    def eraseOverlapIntervals(self, intervals: list[list[int]]) -> int:
        if not intervals:
            return 0
        intervals.sort(key = lambda x:x[1])
        n = len(intervals)
        right = intervals[0][1]
        ans = 1
        for i in range(1,n):
            if intervals[i][0] >= right:
                ans += 1
                right = intervals[i][1]
        return n - ans





t = Solution()
print(t.eraseOverlapIntervals([[1,2],[2,3],[3,4],[1,3]]))
print(t.eraseOverlapIntervals([[1,2], [1,2], [1,2]]))
print(t.eraseOverlapIntervals( [ [1,2], [2,3] ]))



