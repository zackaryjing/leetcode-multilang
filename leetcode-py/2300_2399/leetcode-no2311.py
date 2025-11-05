# problem: https://leetcode.cn/problems/longest-binary-subsequence-less-than-or-equal-to-k/
from typing import *


class Solution:
    def longestSubsequence(self, s: str, k: int) -> int:
        n = len(s)
        base = 1
        cur = 0
        zeroCnt = s.count('0')
        oneCnt = 0
        for i in range(n - 1, -1, -1):
            if s[i] == '1':
                cur += base
                oneCnt += 1
            base *= 2
            if cur > k:
                oneCnt -= 1
                break
        return oneCnt + zeroCnt

def main():
    test = Solution()
    print(test.longestSubsequence("1001010", 5))
    print(test.longestSubsequence("00101001", 1))


if __name__ == "__main__":
    main()

#
# Created by: zhiya At: 6/14/2025 8:32 PM
#
