from itertools import *
class Solution(object):
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []
        for i in range(len(nums)+1):
            for j in combinations(nums,i):
                a = sorted(list(j))
                if not a in res:
                    res.append(a)
        return res

t = Solution()
print(t.subsetsWithDup([1,2,2]))
print(t.subsetsWithDup([4,4,4,1,4]))



