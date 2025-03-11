from typing import *
import math


class Solution:
    def divisorSubstrings(self, num: int, k: int) -> int:
        ans = 0
        n: int = len(str(num))
        for i in range(n - k + 1):
            sub = ((num % (10 ** (i + k))) // (10 ** i))
            if sub != 0:
                if num % sub == 0:
                    ans += 1
        return ans


def main():
    test = Solution()
    # print(test.divisorSubstrings(240, 2))
    print(test.divisorSubstrings(1000000000, 1))
    # print(test.divisorSubstrings(1000000000, 1))


if __name__ == "__main__":
    main()
