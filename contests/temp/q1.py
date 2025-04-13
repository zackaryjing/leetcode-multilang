# problem:
from typing import *


class Solution:
    def findClosest(self, x: int, y: int, z: int) -> int:
        return 1 if abs(x - z) < abs(y - z) else (0 if abs(x - z) == abs(y - z) else 2)


def main():
    test = Solution()
    print(test.findClosest(2, 7, 4))
    print(test.findClosest(2, 5, 6))


if __name__ == "__main__":
    main()

#
# Created by: ASUS At: 2025/4/13 10:33
#
