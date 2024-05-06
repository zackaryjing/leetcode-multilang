from itertools import accumulate
from sortedcontainers import sortedset
class Solution2:
    def leastBricks(self, wall: list[list[int]]) -> int:
        pro = list(map(lambda x:list(accumulate(x)),wall))
        candidate = sorted(list(set(sum(pro,[]))))
        min = n = len(wall)
        candidate.pop()
        for i in candidate:
            mid = 0
            j = 0
            while mid < min and j < n:
                # print(i,pro[j],mid)
                mid += i not in pro[j]
                j += 1
            min = mid
        return min

class Solution:
    def leastBricks(self, wall: list[list[int]]) -> int:
        n = len(wall)
        pro = list(map(lambda x:list(accumulate(x)),wall))
        mid = sum(pro,[])
        candidate = sorted(list(set(mid)))
        candidate.pop()
        res = 0
        for i in candidate:
            res = max(mid.count(i),res)
        return n-res


t = Solution()
print(t.leastBricks([[1,2,2,1],[3,1,2],[1,3,2],[2,4],[3,1,2],[1,3,1,1]]))
print(t.leastBricks([[1],[1],[1]]))
