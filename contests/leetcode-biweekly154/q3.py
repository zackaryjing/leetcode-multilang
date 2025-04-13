from typing import *
from itertools import combinations


class Solution:
    def uniqueXorTriplets(self, nums: List[int]) -> int:
        if not nums:
            return 0

        max_num = max(nums)
        m = max_num.bit_length()
        L = 1 << m

        f = [0] * L
        for x in nums:
            f[x] += 1

        def fwht(a, invert=False):
            n = len(a)
            step = 1
            while step < n:
                for i in range(0, n, step * 2):
                    for j in range(i, i + step):
                        u = a[j]
                        v = a[j + step]
                        a[j] = u + v
                        a[j + step] = u - v
                step *= 2
            if invert:

                for i in range(n):
                    a[i] //= n

        fwht(f)

        for i in range(L):
            f[i] = f[i] ** 3

        fwht(f, invert=True)

        ans = sum(1 for x in f if x > 0)
        return ans


def main():
    test = Solution()
    nums = [1, 2, 3]
    print(test.uniqueXorTriplets(list(range(1, 4))))
    print(test.uniqueXorTriplets(list(range(1, 5))))
    print(test.uniqueXorTriplets(list(range(1, 6))))
    print(test.uniqueXorTriplets(list(range(1, 7))))
    print(test.uniqueXorTriplets(list(range(1, 8))), 8)
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


class Solution2:
    def uniqueXorTriplets(self, nums: List[int]) -> int:
        res = set(nums)
        nums = list(res)
        for x, y, z in combinations(nums, 3):
            res.add(x ^ y ^ z)
        return len(res)
