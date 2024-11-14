from typing import *
class Solution:
    def matrixSum(self, nums: List[List[int]]) -> int:
        for i in range(len(nums)):
            nums[i].sort()
        # print(nums)
        return sum(map(lambda x:max(x),zip(*nums)))


t = Solution()
print(t.matrixSum([[7,2,1],[6,4,2],[6,5,3],[3,2,1]]))
print(t.matrixSum([[1,1,1],[1,1,1],[1,1,1],[1,1,1],[1,1,1]]))
print(t.matrixSum([[1]]))
