class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        start = bin(left)[::-1]
        n = len(start)-2
        res = []
        for i in range(n):
            if start[i] == "0":
                res.append("0")
            else:
                if (left + 2 ** i)>>(i+1)<<(i+1) <= right:
                    res.append("0")
                else:
                    res.append("1")
        return int("".join(res)[::-1],2)
class Solution:
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        res = 0
        i = 0
        while left > 0:
            # print(left,(left + 1)<<i)
            if left & 1 and (left + 1)<<i > right:
                res += 2 ** i
            i += 1
            left >>= 1
        return res
t = Solution()
print(t.rangeBitwiseAnd(5,7))
print(t.rangeBitwiseAnd(0,0))
print(t.rangeBitwiseAnd(1,2147483647))
print(t.rangeBitwiseAnd(3,4))
