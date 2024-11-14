from typing import *
from itertools import filterfalse
class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        nums.sort()
        # print(nums)
        return sum([nums[i] for i in range(len(nums)) if i % 2 == 0])
    
t = Solution()
print(t.arrayPairSum( [1,4,3,2]))
print(t.arrayPairSum([6,2,6,5,1,2]))
