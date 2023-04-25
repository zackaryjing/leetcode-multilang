from itertools import *
class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        for i in range(len(nums)+1):
            res.extend(list(map(list,combinations(nums,i))))
        return res
t = Solution()
print(t.subsets([1,2,3,4,5,6]))
print(t.subsets([1,2,3]))
print(t.subsets([0]))
