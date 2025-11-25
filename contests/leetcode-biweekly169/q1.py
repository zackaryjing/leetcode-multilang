# problem: https://leetcode.cn/contest/biweekly-contest-169/problems/minimum-moves-to-equal-array-elements-iii/
from typing import *


class Solution:
    def minMoves(self, nums: List[int]) -> int:
        return len(nums) * max(nums) - sum(nums)


def main():
    test = Solution()
    print(test.minMoves([2, 1, 3]))
    print(test.minMoves([4, 4, 5]))


if __name__ == "__main__":
    main()

#
# Created by: ASUS At: 11/8/2025 10:33 PM 
#
