from math import ceil
from sortedcontainers import SortedList
class Solution:
    def maxKelements(self, nums: list[int], k: int) -> int:
        mark = 0
        if not nums:
            return 0
        for i in range(k):
            mid = max(nums)
            mark += mid
            nums.remove(mid)
            nums.append(ceil(mid / 3))
        return mark
class Solution:
    def maxKelements(self, nums: list[int], k: int) -> int:
        mark = 0
        if not nums:
            return 0
        a = SortedList(nums)
        for i in range(k):
            mid = a.pop()
            mark += mid
            a.add(ceil(mid / 3))
        return mark
t = Solution()
print(t.maxKelements([10,10,10,10,10],5))
print(t.maxKelements([1,10,3,3,3],3))
print(t.maxKelements([],3))
