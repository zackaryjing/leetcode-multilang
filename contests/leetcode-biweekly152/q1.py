# problem: unique-3-digit-even-numbers
from typing import *
from itertools import permutations, combinations


class Solution:
    def totalNumbers(self, digits: List[int]) -> int:
        ans = 0
        res = set()
        for k in permutations(digits, 3):
            if k[0] != 0 and k[2] % 2 == 0:
                res.add(k[0] * 100 + k[1] * 10 + k[2])
        return len(res)


def main():
    test = Solution()
    print(test.totalNumbers([1, 2, 3, 4]))
    print(test.totalNumbers([0, 2, 2]))
    print(test.totalNumbers([6, 6, 6]))
    print(test.totalNumbers([1, 3, 5]))
    print(test.totalNumbers([1, 6, 2, 8, 7]))


if __name__ == "__main__":
    main()
