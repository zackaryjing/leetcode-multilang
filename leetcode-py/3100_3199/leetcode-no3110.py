# problem: score-of-a-string
from functools import reduce
from itertools import starmap, pairwise
from typing import *


class Solution:
    def scoreOfString(self, s: str) -> int:
        return sum(starmap(lambda x, y: abs(ord(x) - ord(y)), pairwise(s)))


def main():
    test = Solution()
    print(test.scoreOfString("hello"))


if __name__ == "__main__":
    main()
