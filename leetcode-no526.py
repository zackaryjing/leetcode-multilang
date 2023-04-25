class Solution:
    def countArrangement(self, n: int) -> int:
        mask = 1 << n
        f = [[0]*mask for _ in range(n+1)]
        f[0][0] = 1
        for i in range(1,n+1):
            for state in range(mask):
                for k in range(1,n+1):
                    if (state >> k-1)&1==0:
                        continue
                    if k % i != 0 and i % k != 0:
                        continue
                    f[i][state] += f[i-1][state & (~(1<<(k-1)))]
        for i in f:
            print(i)
        return f[n][mask-1]



t = Solution()
print(t.countArrangement(4))