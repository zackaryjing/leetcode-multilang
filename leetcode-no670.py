class Solution:
    def maximumSwap(self, num: int) -> int:
        num = list(str(num))
        renum = sorted(num,reverse=True)
        n = len(num)
        for i in range(n):
            if (maxum := renum[i]) > (minum := num[i]):
                num[i] = maxum
                break
        for j in range(n-1,-1,-1):
            if num[j] == maxum:
                num[j] = minum
                break
        return int(''.join(num))




t = Solution()
print(t.maximumSwap(2736))
print(t.maximumSwap(23645426))
print(t.maximumSwap(1))
print(t.maximumSwap(10))
