# problem:
from pprint import pprint
from typing import *

from attr.validators import max_len


class Solution:
    def longestPalindrome(self, s: str, t: str) -> int:
        st = s + t
        d = len(s)
        n = len(st)
        if n == 0:
            return 0
        dp1 = [[0] * n for _ in range(n)]
        dp2 = [[0] * n for _ in range(n)]
        dp3 = [[0] * n for _ in range(n)]
        for i in range(n):
            dp3[i][i] = 1
            dp2[i][i] = 1
            dp1[i][i] = 1
        ans = 0
        for length in range(2, n + 1):
            for i in range(n - length + 1):
                j = i + length - 1
                if i < d <= j:
                    dp2[i][j] = max(dp1[i + 1][j], dp1[i][j - 1],dp2[i + 1][j], dp2[i][j - 1],  1)
                elif j < d:
                    dp2[i][j] = max(dp1[i][j - 1], dp2[i][j - 1])
                else:
                    dp2[i][j] = max(dp1[i + 1][j], dp2[i + 1][j])

                if st[i] == st[j]:
                    if length == 2 or dp1[i + 1][j - 1]:
                        dp1[i][j] = dp1[i + 1][j - 1] + 2
                    # dp2[i][j] = dp2[i + 1][j - 1] + 2
                    if length == 2 or dp2[i + 1][j - 1] or dp3[i + 1][j - 1]:
                        if i < d <= j:
                            if dp2[i + 1][j - 1]:
                                dp3[i][j] = max(dp2[i + 1][j - 1] + 2,dp3[i][j])
                            if dp3[i + 1][j - 1]:
                                dp3[i][j] = max(dp3[i][j],dp3[i + 1][j - 1] + 2)
                        else:
                            if dp3[i + 1][j - 1]:
                                dp3[i][j] = dp3[i + 1][j - 1] + 2
                else:
                    dp1[i][j] = 0
                    dp3[i][j] = 0
                ans = max(ans, dp3[i][j], dp2[i][j], dp1[i][j])

        pprint(dp1)
        pprint(dp2)
        pprint(dp3)

        return ans


def main():
    test = Solution()
    print(test.longestPalindrome("a", "a"), 2)
    print(test.longestPalindrome("abc", "def"), 1)
    print(test.longestPalindrome("b", "aaaa"), 4)
    print(test.longestPalindrome("abcde", "ecdba"), 5)
    print(test.longestPalindrome("f", "zzvz"), 3)
    print(test.longestPalindrome("n", "fazrf"), 1)
    print(test.longestPalindrome("hc", "jooh"), 4)


if __name__ == "__main__":
    main()
