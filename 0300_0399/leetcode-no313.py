from typing import *


class Solution:
    def nthSuperUglyNumber(self, n: int, primes: List[int]) -> int:
        N = len(primes)
        pointers = [1] * N
        res = [0, 1]
        for j in range(1, n):
            res.append(min(tmp := [res[pointers[i]] * primes[i] for i in range(N)]))
            for t in range(N):
                if res[j + 1] == tmp[t]:
                    pointers[t] += 1
        #     print(tmp,pointers,res[j])
        # print(res)
        return res[n]


t = Solution()
print(t.nthSuperUglyNumber(12, [2, 7, 13, 19]))
