from typing import *
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        left = 0
        n = right = (len(numbers) - 1)
        while left <= n and right >= 0:
            if numbers[left] + numbers[right] > target:
                right -= 1
            elif numbers[right] + numbers[left] < target:
                left += 1
            else:
                return [left+1,right+1]

t = Solution()
print(t.twoSum([2,7,11,15],9))