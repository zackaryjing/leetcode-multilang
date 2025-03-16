# problem: 
from typing import *
import bisect


class Solution:
    def maxSum(self, nums: List[int]) -> int:
        nums = list(set(nums))
        nums.sort()
        index = bisect.bisect(nums, 0)  # 找到第一个大于0的元素的索引
        if index >= len(nums):
            return max(nums)
        return sum(nums[index:])  # 计算所有大于0的数的和


def main():
    test = Solution()
    print(test.maxSum([1, 2, 3, 4, 5]))
    print(test.maxSum([1, 1, 0, 1, 1]))
    print(test.maxSum([1,2,-1,-2,1,0,-1]))
    print(test.maxSum([-1,-1,-1]))
    print(test.maxSum([10]))
    print(test.maxSum([0]))
    print(test.maxSum([-10]))


if __name__ == "__main__":
    main()
