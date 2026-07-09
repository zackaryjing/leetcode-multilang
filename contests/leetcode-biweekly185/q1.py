# problem:
from typing import *


class Solution:
    def createGrid(self, m: int, n: int) -> list[str]:
        res = ["." * n]
        res.extend(list(('#' * (n - 1) + '.') for _ in range(m - 1)))
        return res


def main():
    test = Solution()
    print(test.createGrid(5, 6))


if __name__ == "__main__":
    main()

#
# Created by: ASUS At: 6/20/2026 10:26 PM
#
