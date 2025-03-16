# problem: count-of-substrings-containing-every-vowel-and-k-consonants-i/
from typing import *
from collections import defaultdict
from pprint import pp


class Solution:
    def countOfSubstrings(self, word: str, k: int) -> int:
        n = len(word)
        val: defaultdict[Any, int] = defaultdict(lambda: 32)
        val['a'] = 1
        val['e'] = 2
        val['i'] = 4
        val['o'] = 8
        val['u'] = 16
        ans = 0
        last = [0] * n
        for i in range(n):
            last[i] = val[word[i]]
        for length in range(1, n):
            cur = [0] * n
            for i in range(0, n - length):
                v = val[word[i + length]]
                if v == 32:
                    temp = last[i + length - 1] + v
                else:
                    temp = last[i + length - 1] | v
                cur[i + length] = temp
                if (temp % 32) == 31 and (temp >> 5) == k:
                    ans += 1
            last = cur
        return ans


class Solution2:
    def countOfSubstrings(self, word: str, k: int) -> int:
        n = len(word)
        substr_status = [[0] * n for _ in range(n)]
        val: defaultdict[Any, int] = defaultdict(lambda: 32)
        val['a'] = 1
        val['e'] = 2
        val['i'] = 4
        val['o'] = 8
        val['u'] = 16
        ans = 0
        for i in range(n):
            substr_status[i][i] = val[word[i]]
        for length in range(1, n):
            for i in range(0, n - length):
                v = val[word[i + length]]
                if v == 32:
                    temp = substr_status[i][i + length - 1] + v
                else:
                    temp = substr_status[i][i + length - 1] | v
                substr_status[i][i + length] = temp
                if (temp % 32) == 31 and (temp >> 5) == k:
                    ans += 1
        return ans


def main():
    test = Solution()
    print(test.countOfSubstrings("aeioqq", 1))
    print(test.countOfSubstrings("aeiou", 0))
    print(test.countOfSubstrings("ieaouqqieaouqq", 1))


if __name__ == "__main__":
    main()
