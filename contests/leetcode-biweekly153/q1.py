

# problem:
from typing import *


class Solution:
    def reverseDegree(self, s: str) -> int:
        ans = 0
        for pos,ch in enumerate(list(s)):
            ans += (pos + 1) * (26 - (ord(ch) - ord('a')))
        return ans


def main():
    test = Solution()
    print(test.reverseDegree("abc"))
    print(test.reverseDegree("zaza"))


if __name__ == "__main__":
    main()
