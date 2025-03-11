import heapq
from typing import *


class Solution:
    def findMaxSum(self, nums1: List[int], nums2: List[int], k: int) -> List[int]:
        n = len(nums1)
        nums = list(zip(nums1, nums2, range(n)))
        nums.sort()
        min_heap = []
        total = 0
        ans = [0 for _ in range(n)]
        prev = -1
        temp_val = 0
        for num in nums:
            # print(ans)
            if num[0] > prev:
                temp_val = total
                prev = num[0]
            ans[num[2]] = temp_val

            total += num[1]
            if len(min_heap) < k:
                heapq.heappush(min_heap, num[1])  # 先填满堆
            else:
                diff = heapq.heappushpop(min_heap, num[1])  # 维护堆的大小
                total -= diff
        return ans


def main():
    test = Solution()
    print(test.findMaxSum([18, 11, 24, 9, 10, 11, 7, 29, 16], [28, 26, 27, 4, 2, 19, 23, 1, 2], 1))
    print(test.findMaxSum([4, 2, 1, 5, 3], [10, 20, 30, 40, 50], 2))
    print(test.findMaxSum([2,2,2,2], [3,1,2,3], 1))


if __name__ == "__main__":
    main()
