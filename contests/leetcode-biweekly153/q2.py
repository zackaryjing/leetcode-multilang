# problem:
from typing import *


class Solution:
    def maxActiveSectionsAfterTrade(self, s: str) -> int:
        if not s:
            return 0
        one_cnt = s.count('1')
        n = len(s)
        s = "1" + s + "1"
        letter = []
        cnt = []
        last = '1'
        cur_len = 0
        for ch in s:
            if ch == last:
                cur_len += 1
            else:
                cnt.append(cur_len)
                letter.append(last)
                cur_len = 1
                last = ch
        cnt.append(cur_len)
        letter.append(last)
        # print(cnt, letter)
        ans = 0
        if len(letter) < 5:
            return one_cnt
        new_len = len(letter)
        if new_len == 5:
            return n
        for i in range(4, new_len, 2):
            ans = max(cnt[i - 3] + cnt[i - 1], ans)
        # print(one_cnt, ans)
        return one_cnt + ans


def main():
    test = Solution()
    print(test.maxActiveSectionsAfterTrade("0101011111"), 9)
    print(test.maxActiveSectionsAfterTrade("1101"), 3)
    print(test.maxActiveSectionsAfterTrade("101"), 2)
    print(test.maxActiveSectionsAfterTrade("1111011111"), 9)
    print(test.maxActiveSectionsAfterTrade("1111"), 4)
    print(test.maxActiveSectionsAfterTrade("1"), 1)
    print(test.maxActiveSectionsAfterTrade("01"), 1)
    print(test.maxActiveSectionsAfterTrade("0100"), 4)
    print(test.maxActiveSectionsAfterTrade("1000100"), 7)
    print(test.maxActiveSectionsAfterTrade("01010"), 4)
    print(test.maxActiveSectionsAfterTrade("1101111001"), 10)


if __name__ == "__main__":
    main()
