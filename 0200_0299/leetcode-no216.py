def getdig(num):
    res = 0
    for i in range(9):
        res += (num >> i) & 1
    return res
class Solution2:
    def combinationSum3(self, k: int, n: int) -> list[list[int]]:
        for g in range(0,9):
            for i in range(2**(g-1),2**g):
                total = 0
                if getdig(i) == 1:
                    pass
                for j in range(g+1):
                    if (i >> j) & 1:
                        total += i + 1
                if total == n:
                    pass
class Solution:
    def combinationSum3(self, k: int, n: int) -> list[list[int]]:
        res = []
        for j in range(2**9):
            total = 0
            mid = []
            if getdig(j) == k:
                for i in range(9):
                    if (j >> i) & 1:
                        total += i + 1
                        mid.append(i+1)
            if total == n:
                res.append(mid)
        return res
t = Solution()
print(t.combinationSum3(3,7))
print(t.combinationSum3(3,9))
