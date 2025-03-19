# problem: convert-an-array-into-a-2d-array-with-conditions
from collections import defaultdict
from typing import *


class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        times = defaultdict(int)
        max_cnt = 0
        for num in nums:
            times[num] += 1
            max_cnt = max(max_cnt, times[num])
        ans: List[List[int]] = [[] for _ in range(max_cnt)]
        for k, v in times.items():
            for j in range(v):
                ans[j].append(k)
        return ans


def main():
    test = Solution()
    print(test.findMatrix([1, 3, 4, 1, 2, 3, 1]))


if __name__ == "__main__":
    main()
