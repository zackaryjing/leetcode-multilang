# problem: https://leetcode.cn/problems/widest-vertical-area-between-two-points-containing-no-points/?envType=problem-list-v2&envId=FeuPdeiM
from typing import *
from itertools import pairwise


class Solution:
    def maxWidthOfVerticalArea(self, points: List[List[int]]) -> int:
        return max(map(lambda y: y[1] - y[0], list(pairwise(sorted([x[0] for x in points])))))


def main():
    test = Solution()
    print(test.maxWidthOfVerticalArea([[8, 7], [9, 9], [7, 4], [9, 7]]))


if __name__ == "__main__":
    main()

#
# Created By ASUS At 4/17/2026 11:02 PM
#
