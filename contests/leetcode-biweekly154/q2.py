# problem:
from itertools import permutations, combinations
from typing import *


class Solution2:
    def uniqueXorTriplets(self, nums: List[int]) -> int:
        res = set(nums)
        for x, y, z in combinations(nums, 3):
            res.add(x ^ y ^ z)
        return len(res)


def next_power_of_2(n):
    if n <= 1:
        return 1
    # 如果n本身是2的幂，直接返回n
    if (n & (n - 1)) == 0:
        return n
    # 通过位运算调整n为下一个2的幂
    n -= 1  # 先减1
    n |= n >> 1
    n |= n >> 2
    n |= n >> 4
    n |= n >> 8
    n |= n >> 16  # 对于n < 10^5，最多16位足够
    return n + 1  # 加1，得到下一个2的幂


class Solution:
    def uniqueXorTriplets(self, nums: List[int]) -> int:
        if len(nums) < 3:
            return len(nums)
        return next_power_of_2(len(nums) + 1)


def main():
    test = Solution2()
    print(test.uniqueXorTriplets(list(range(1, 4))))
    print(test.uniqueXorTriplets(list(range(1, 5))))
    print(test.uniqueXorTriplets(list(range(1, 6))))
    print(test.uniqueXorTriplets(list(range(1, 7))))
    print(test.uniqueXorTriplets(list(range(1, 8))))
    print(test.uniqueXorTriplets(list(range(1, 9))), 9)
    print(test.uniqueXorTriplets(list(range(1, 10))))
    print(test.uniqueXorTriplets(list(range(1, 11))))
    print(test.uniqueXorTriplets(list(range(1, 12))))
    print(test.uniqueXorTriplets(list(range(1, 13))))
    print(test.uniqueXorTriplets(list(range(1, 14))))
    print(test.uniqueXorTriplets(list(range(1, 15))))
    print(test.uniqueXorTriplets(list(range(1, 16))))
    print(test.uniqueXorTriplets(list(range(1, 17))))


if __name__ == "__main__":
    main()

#
# Created by: ASUS At: 2025/4/12 22:36
#
