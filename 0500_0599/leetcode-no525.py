from itertools import starmap
from itertools import pairwise
from itertools import accumulate
from collections import defaultdict
class Solution:
    """
    想了半天的算法是错误的，根本用不了，太傻了。
    """
    def findMaxLength(self, nums: list[int]) -> int:
        nums = list(map(lambda x:2*x-1,nums))
        print(nums)
        nums = list(starmap(lambda x, y: x + y, pairwise(nums)))
        print(nums)
        n = len(nums)
        maxum = 2 if 0 in nums else 0
        times = 2 if 0 in nums else 0
        cnt = 0
        while times <= n:
            times += 2
            cnt += 2
            mid = []
            for i in range(n-cnt):
                mid.append(nums[i]+nums[i+2])
            nums = mid
            print(nums,times,n)
            if 0 in nums and times > maxum:
                maxum = times
        return maxum


class Solution:
    def findMaxLength(self, nums: list[int]) -> int:
        nums = list(accumulate(map(lambda x:2*x-1,nums)))
        sums = {0:-1}
        # print(nums)
        maxum = 0
        n = len(nums)
        for i in range(n):
            # print(sums)
            # print(i)
            if (a := sums.get(g := nums[i],-2)) == -2:
                # print(i,nums[i],a)
                sums[g] = i
            else:
                # print(i,a)
                if (t := (i - a)) > maxum:
                    maxum = t
        return maxum





t = Solution()
# print(t.findMaxLength([0,1,0,1,1,0,1,0,0,0,1,1,0,1,1,0,1]))
print(t.findMaxLength([0,0,1]))
# print(t.findMaxLength([0,1]))
# print(t.findMaxLength([0,1,0]))
# print(t.findMaxLength([0,1,0,1]))
# print(t.findMaxLength([0,0,1,0,0,0,1,1]))
