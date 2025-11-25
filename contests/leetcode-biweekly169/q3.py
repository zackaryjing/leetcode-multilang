# problem: https://leetcode.cn/contest/biweekly-contest-169/problems/longest-non-decreasing-subarray-after-replacing-at-most-one-element/ 
from typing import *


class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        ended = [1] * n
        started = [1] * n
        for i in range(1, n):
            if nums[i] >= nums[i - 1]:
                ended[i] = ended[i - 1] + 1
        for i in range(n - 2, -1, -1):
            if nums[i] <= nums[i + 1]:
                started[i] = started[i + 1] + 1
        res = 1
        if n >= 2:
            res = 2
        # print("e", ended)
        # print("s", started)
        for i in range(0, n):
            if 1 <= i < n - 1 and nums[i + 1] >= nums[i - 1]:
                # print("1", nums[i + 1], nums[i - 1], i)
                res = max(res, ended[i - 1] + started[i + 1] + 1)
            else:
                # print("2", nums[i + 1], nums[i - 1], i)
                if i < n - 1:
                    res = max(res, started[i + 1] + 1)
                if i >= 1:
                    res = max(res, ended[i - 1] + 1)
        return res


def main():
    test = Solution()
    print(test.longestSubarray([1, 2, 3, 1, 2]))
    print(test.longestSubarray([2, 2, 2, 2, 2]))
    print(test.longestSubarray([-3, 8, -7]))


if __name__ == "__main__":
    main()

#
# Created by: ASUS At: 11/8/2025 10:48 PM 
#
