# problem: https://leetcode.cn/contest/biweekly-contest-182/problems/minimum-flips-to-make-binary-string-coherent/
from collections import Counter
from itertools import count
from typing import *

class Solution:
    def minFlips(self, s: str) -> int:
        cnts = Counter(s)
        candidate = 1000000
        if (cnts["1"] == 2 and s[0] == "1" and s[-1] == "1"):
            return 0
        if (cnts["1"] >= 2):
            candidate = cnts["1"] - 2
            firstOne = 0
            secondOne = 0
            for c in s:
                if c == "1":
                    break
                else:
                    firstOne += 1
            for c in reversed(s):
                if c == "1":
                    break
                else:
                    secondOne += 1
            candidate += firstOne + secondOne
        return max(min([cnts["0"], cnts["1"] - 1, candidate]), 0)


def main():
    test = Solution()
    print(test.minFlips("1010"), "e1")
    print(test.minFlips("0110"), "e1")
    print(test.minFlips("1000"), "e0")
    print(test.minFlips("1001"), "e0")
    print(test.minFlips("100011"), "e1")


if __name__ == "__main__":
    main()

#
# Created by: jing At: 2026-05-09 22:37:28
#
