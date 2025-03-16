# problem:
from typing import *
import bisect


class Solution:
    def solveQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        # 构建二维数组 (值, 索引)
        indexed_nums = [(num, i) for i, num in enumerate(nums)]
        indexed_nums.sort()  # 按值排序，值相同按索引排序

        # 构建一个字典，存储每个值对应的所有索引（升序排列）
        value_to_indices = {}
        for num, index in indexed_nums:
            if num not in value_to_indices:
                value_to_indices[num] = []
            value_to_indices[num].append(index)

        result = []
        n = len(nums)

        for q in queries:
            value = nums[q]  # 查询的值
            if value not in value_to_indices or len(value_to_indices[value]) == 1:
                result.append(-1)  # 只有一个出现或者不存在
                continue

            # 该值所有的索引
            indices = value_to_indices[value]
            pos = bisect.bisect_left(indices, q)  # 找到 q 应该插入的位置

            min_dist = float('inf')

            indices_len = len(indices)
            right_pos = indices[(pos + 1 + indices_len) % indices_len]
            min_dist = min(min_dist, abs(q - right_pos), min(q, right_pos) + n - max(q, right_pos))
            left_pos = indices[(pos - 1 + indices_len) % indices_len]
            min_dist = min(min_dist, abs(q - left_pos), min(q, left_pos) + n - max(q, left_pos))

            result.append(min_dist if min_dist != float('inf') else -1)

        return result


def main():
    test = Solution()
    print(test.solveQueries([1, 3, 1, 4, 1, 3, 2], [0, 3, 5]))  # [2, -1, 3]
    print(test.solveQueries([1, 2, 3, 4], [0, 1, 2, 3]))  # [-1, -1, -1, -1]
    print(test.solveQueries([1], [0]))  # [-1, -1, -1, -1]
    print(test.solveQueries([], []))  # [-1, -1, -1, -1]
    print(test.solveQueries([6, 12, 17, 9, 16, 7, 6], [5, 6, 0, 4]))  # [-1, -1, -1, -1]


if __name__ == "__main__":
    main()
