# problem: https://leetcode.cn/contest/biweekly-contest-169/problems/count-subarrays-with-majority-element-ii/
from typing import *


class Solution2:
    def countMajoritySubarrays(self, nums: List[int], target: int) -> int:
        n = len(nums)
        times = [0] * (n + 1)
        for i in range(0, n):
            if nums[i] == target:
                times[i + 1] = times[i] + 1
            else:
                times[i + 1] = times[i]
        res = 0
        added = 0
        for i in range(1, n + 1):
            if i > 1 and nums[i - 2] != target:
                res += added
                continue
            else:
                added = 0

            j = i
            while j < n + 1:
                count = times[j] - times[i - 1]
                if count > (j - i + 1) / 2:
                    added += 1
                else:
                    j += (j - i + 1) - 2 * count
                j += 1
            res += added
        return res


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
        added = 0
        for i in range(1, n + 1):
            if i > 1 and nums[i - 2] != target:
                res += added
            else:
                added = 0

            j = i
            while j < n + 1:
                count = times[j] - times[i - 1]
                if count > (j - i + 1) / 2:
                    added += 1
                else:
                    j += (j - i + 1) - 2 * count
                j += 1
            res += added
        return res


def main():
    test = Solution()
    print(test.countMajoritySubarrays([1, 2, 2, 3], target=2))
    print(test.countMajoritySubarrays([1, 1, 1, 1], target=1))
    print(test.countMajoritySubarrays([1, 2, 3], target=4))


if __name__ == "__main__":
    main()

#
# Created by: ASUS At: 11/8/2025 11:07 PM
#

