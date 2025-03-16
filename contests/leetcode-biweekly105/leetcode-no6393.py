from typing import *
class Solution:
    def maxStrength(self, nums: List[int]) -> int:
        positive = [i for i in nums if i > 0]
        negative = [i for i in nums if i < 0]
        negative.sort()
        ans = 1
        n = len(negative)
        if not positive:
            if n <= 1:
                if 0 in nums:
                    return 0
                return negative[0]
        for i in positive:
            ans *= i
        if n % 2:
            negative.pop()
        for j in negative:
            ans *= j
        return ans


t = Solution()
print(t.maxStrength([3,-1,-5,2,5,-9]))
print(t.maxStrength([3,4,2,-4,-2,-3]))
print(t.maxStrength([-4,-5,-4]))
print(t.maxStrength([-1,-1]))
print(t.maxStrength([-10,0]))
print(t.maxStrength([-10,-10,0]))
print(t.maxStrength([-10]))
print(t.maxStrength([]))

