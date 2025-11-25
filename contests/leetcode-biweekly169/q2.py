# problem:  https://leetcode.cn/contest/biweekly-contest-169/problems/count-subarrays-with-majority-element-i/
from typing import *


class Solution:
    def countMajoritySubarrays(self, nums: List[int], target: int) -> int:
        n = len(nums)
        times = [0] * (n + 1)
        for i in range(0, n):
            if nums[i] == target:
                times[i + 1] = times[i] + 1
            else:
                times[i + 1] = times[i]
        res = 0
        for i in range(1, n + 1):
            for j in range(i, n + 1):
                if times[j] - times[i - 1] > (j - i + 1) / 2:
                    res += 1
        return res


def main():
    test = Solution()
    print(test.countMajoritySubarrays([1, 2, 2, 3], target=2))
    print(test.countMajoritySubarrays([1, 2, 2, 3], target=2))


if __name__ == "__main__":
    main()

#
# Created by: ASUS At: 11/8/2025 10:35 PM
#
