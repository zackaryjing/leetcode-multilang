from typing import *


class Solution:
    def isBoomerang(self, points: List[List[int]]) -> bool:
        f, s, t = points
        if f == s or s == t or f == t:
            return False
        if f[1] == s[1] or f[1] == t[1]:
            if f[1] == s[1] and f[1] != t[1] or f[1] != s[1] and f[1] == t[1]:
                return True
            return False
        return abs(((f[0] - s[0]) / (f[1] - s[1])) - ((f[0] - t[0]) / (f[1] - t[1]))) > 1e-5


def main():
    test = Solution()
    print(test.isBoomerang([[1, 1], [2, 3], [3, 2]]))
    print(test.isBoomerang([[1, 1], [2, 2], [3, 3]]))
    print(test.isBoomerang([[0, 0], [0, 2], [2, 1]]))


if __name__ == "__main__":
    main()
