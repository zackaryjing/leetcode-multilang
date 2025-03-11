from typing import *

from pyasn1_modules.rfc7292 import friendlyName


class Solution:
    def sumOfBeauties(self, nums: List[int]) -> int:
        n = len(nums)
        max_num = 0
        min_num = 10 ** 6
        prefix = [0 for _ in range(n)]
        surfix = [0 for _ in range(n)]

        for i in range(n):
            num = nums[i]
            max_num = max(num, max_num)
            prefix[i] = max_num
        for i in range(n - 1, -1, -1):
            num = nums[i]
            min_num = min(num, min_num)
            surfix[i] = min_num
        first = [prefix[i - 1] < nums[i] < surfix[i + 1] for i in range(1, n - 1)]
        second = [nums[i - 1] < nums[i] < nums[i + 1] and not first[i - 1] for i in range(1, n - 1)]
        return sum(first) * 2 + sum(second)


def main():
    test = Solution()
    print(test.sumOfBeauties([1, 2, 3]))
    print(test.sumOfBeauties([3, 2, 1]))
    print(test.sumOfBeauties([2, 4, 6, 4]))
    print()


class Solution2:
    def sumOfBeauties(self, nums: List[int]) -> int:
        n = len(nums)
        combine = [[nums[i], i] for i in range(len(nums))]
        sorted_combine = sorted(combine)
        # print(combine)
        # print(sorted_combine)
        first = [combine[i] == sorted_combine[i] and sorted_combine[i - 1][0] != sorted_combine[i][0] !=
                 sorted_combine[i + 1][0] for i in range(1, n - 1)]
        # print(first)
        second = [nums[i - 1] < nums[i] < nums[i + 1] and not first[i - 1] for i in range(1, n - 1)]
        # print(second)
        return sum(first) * 2 + sum(second)


if __name__ == "__main__":
    main()
