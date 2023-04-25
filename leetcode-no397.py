from functools import cache
class Solution2:
    def integerReplacement(self, n: int) -> int:
        a = bin(n)
        cnt1 = a.count("1")
        cnt0 = a.count("0")-1
        if not cnt0 == 0:
            return cnt0 + 2*cnt1 - 2
        else:
            return cnt1 + 1

class Solution:
    def integerReplacement(self, n: int) -> int:
        i = 0
        s = bin(n)
        res = 0
        while len(s) != 3:
            # print(s)
            if s[-1] == "0":
                res += 1
                n >>= 1
            else:
                if s[-2] == "0":
                    res += 2
                    n >>= 1
                elif s[-2] == "1" and s[-3] == "1":
                    n += 1
                    res += 1
                else:
                    n -= 1
                    res += 1
            s = bin(n)
        return res


class Solution:
    @cache
    def integerReplacement(self, n: int) -> int:
        if n == 1:
            return 0
        if n % 2 == 0:
            return 1 + self.integerReplacement(n // 2)
        return 2 + min(self.integerReplacement(n//2),self.integerReplacement(n // 2 + 1))



t = Solution()
print(t.integerReplacement(1))
print(t.integerReplacement(2))
print(t.integerReplacement(3))
print(t.integerReplacement(4))
print(t.integerReplacement(8))
print(t.integerReplacement(7))
print(t.integerReplacement(11))
print(t.integerReplacement(1000))
print(t.integerReplacement(65535))
print(t.integerReplacement(100000000))
