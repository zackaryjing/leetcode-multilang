# problem:
from math import factorial
from typing import *
from math import factorial
from collections import Counter


class Solution3:
    def __init__(self):
        self.fact = [1]
        for i in range(1, 101):  # 预计算 0! ~ 100!
            self.fact.append(self.fact[-1] * i)
        self.perm_cache = {}

    def perms(self, freq: dict[str, int]):
        key = tuple(sorted(freq.items()))
        if key in self.perm_cache:
            return self.perm_cache[key]

        total = sum(freq.values())
        res = self.fact[total]
        for v in freq.values():
            res //= self.fact[v]
        self.perm_cache[key] = res
        return res

    def smallestPalindrome(self, s: str, k: int) -> str:
        origin_k = k

        freq = Counter(s)
        mid = ""
        for ch, time in freq.items():
            if time % 2 == 1:
                mid = ch
            freq[ch] = time // 2

        k -= 1
        n = len(s) // 2
        res = ""
        for _ in range(n):
            for ch in sorted(freq):
                if freq[ch] == 0:
                    continue
                freq[ch] -= 1
                perm = self.perms(freq)
                if k >= perm:
                    k -= perm
                    freq[ch] += 1
                else:
                    res += ch
                    break
            else:
                return ""

        return res + mid + res[::-1] if res or mid else ""




class Solution:
    def __init__(self):
        self.fact = [1]
        for i in range(1, 101):
            self.fact.append(self.fact[-1] * i)
        self.perm_cache = {}

    def ensure_factorial(self, n: int):
        while len(self.fact) <= n:
            self.fact.append(self.fact[-1] * len(self.fact))

    def perms(self, freq: dict[str, int]):
        total = sum(freq.values())
        self.ensure_factorial(total)

        key = tuple(sorted(freq.items()))
        if key in self.perm_cache:
            return self.perm_cache[key]

        res = self.fact[total]
        for v in freq.values():
            self.ensure_factorial(v)
            res //= self.fact[v]
        self.perm_cache[key] = res
        return res

    def smallestPalindrome(self, s: str, k: int) -> str:
        freq = Counter(s)
        mid = ""
        for ch, time in freq.items():
            if time % 2 == 1:
                mid = ch
            freq[ch] = time // 2

        k -= 1
        n = len(s) // 2
        res = ""
        for _ in range(n):
            for ch in sorted(freq):
                if freq[ch] == 0:
                    continue
                freq[ch] -= 1
                perm = self.perms(freq)
                if k >= perm:
                    k -= perm
                    freq[ch] += 1
                else:
                    res += ch
                    break
            else:
                return ""

        return res + mid + res[::-1] if res or mid else ""


class Solution2:
    def perms(self, freq: dict[str, int]):
        res = factorial(sum(freq.values()))
        for k in freq.values():
            res //= factorial(k)
        return res

    def smallestPalindrome(self, s: str, k: int) -> str:
        origin_k = k

        freq = Counter(s)
        mid = ""
        for ch, time in freq.items():
            if time % 2 == 1:
                mid = ch
            freq[ch] = time // 2

        # print(freq)
        k -= 1
        n = len(s) // 2
        res: str = ""
        for _ in range(n):
            for ch in sorted(freq):
                if freq[ch] == 0:
                    continue
                freq[ch] -= 1
                perm = self.perms(freq)
                if k >= perm:
                    freq[ch] += 1
                    k -= perm
                else:
                    res += ch
                    break
            else:
                return ""
        if len(res) != 0:
            # print("res: ", res)
            return res + mid + res[::-1]
        else:
            if origin_k == 1:
                return mid
            else:
                return ""


def main():
    test = Solution()
    print(test.smallestPalindrome("dmtmd", 3))
    print(test.smallestPalindrome("a", 1))
    print(test.smallestPalindrome("kxk", 2))
    print(test.smallestPalindrome("abba", 2))
    print(test.smallestPalindrome("aa", 2))
    print(test.smallestPalindrome(
        "ytozlmionsteluzmjhejujmojwyrdqkzvyubzsqmznkcfeyrpatcufykscmtvmutlmvcjssstbiuolhddezimqlctfjvapiczflqyehtxxtheyqlfzcipavjftclqmizeddhlouibtsssjcvmltumvtmcskyfuctapryefcknzmqszbuyvzkqdrywjomjujehjmzuletsnoimlzoty",
        247532))


if __name__ == "__main__":
    main()

#
# Created by: ASUS At: 2025/4/13 11:21 
#
