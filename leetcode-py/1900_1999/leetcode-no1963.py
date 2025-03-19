# problem: minimum-number-of-swaps-to-make-the-string-balanced
import math
from typing import *



class Solution:
    def minSwaps(self, s: str) -> int:
        total = 0
        times = 0
        for i in s:
            if i == '[':
                if total < 0:
                    temp = math.ceil(abs(total) / 2)
                    times += temp
                    total += temp * 2
                total += 1
            elif i == ']':
                total -= 1
        return  times





def main():
    test = Solution()
    print(test.minSwaps("][]["))
    print(test.minSwaps("]]][[["))
    print(test.minSwaps("[]"))


if __name__ == "__main__":
    main()
