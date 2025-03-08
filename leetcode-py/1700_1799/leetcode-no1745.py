from typing import *


class Solution:
    def checkPartitioning(self, s: str) -> bool:
        n: int = len(s)
        dp = [[False for _ in range(n)] for _ in range(3)]
        is_palindromic: List[List[bool]] = [[False for _ in range(n)] for _ in range(n)]
        for i in range(n):
            for j in range(n - i):
                if s[j + i] == s[j]:
                    if i == 0 or i == 1 or is_palindromic[j + 1][j + i - 1]:
                        is_palindromic[j][j + i] = True

        for i in range(0, n):
            dp[0][i] = is_palindromic[0][i]
            for j in range(0, i):
                if dp[0][j] and is_palindromic[j + 1][i]:
                    dp[1][i] = True
                    break
        for j in range(1, n - 1):
            if dp[1][j] and is_palindromic[j + 1][n - 1]:
                return True
        return False


def main():
    test = Solution()
    print(test.checkPartitioning("abcbdd"))
    print(test.checkPartitioning("bcbddxy"))


if __name__ == "__main__":
    main()
