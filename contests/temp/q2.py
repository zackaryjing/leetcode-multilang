# problem:
from typing import *
from collections import defaultdict


class Solution:
    def smallestPalindrome(self, s: str) -> str:
        times = defaultdict(int)
        vchar = []
        mid = []
        for ch in s:
            times[ch] += 1
        for ch, time in times.items():
            if time % 2 == 0:
                vchar.extend([ch] * (time // 2))
            else:
                vchar.extend([ch] * (time // 2))
                mid = [ch]
        res = list(vchar)
        res.sort()
        return "".join(res + mid + res[::-1])


def main():
    test = Solution()
    print(test.smallestPalindrome("asdfasdfi"))
    print(test.smallestPalindrome("babab"))
    print(test.smallestPalindrome("bbbbabab"))


if __name__ == "__main__":
    main()

#
# Created by: ASUS At: 2025/4/13 10:37
#
