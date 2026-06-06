# problem:
from typing import *

class Solution:
    def consecutiveSetBits(self, n: int) -> bool:
        s = bin(n)
        cnts = 0
        for i in range(len(s)):
            if (s[i:].startswith("11")) :
                cnts += 1
        return cnts == 1

def main():
    test = Solution()
    print(test.consecutiveSetBits(6))
    print(test.consecutiveSetBits(93))


if __name__ == "__main__":
    main()

#
# Created by: jing At: 2026-06-06 22:29:19
#