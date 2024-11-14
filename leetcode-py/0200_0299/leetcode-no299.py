class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        n = len(secret)
        data1 = [0] * 10
        data2 = data1[:]
        bulls = cols = 0
        for i in range(n):
            if secret[i] == guess[i]:
                bulls += 1
            else:
                data1[int(secret[i])] += 1
                data2[int(guess[i])] += 1
        for j in range(10):
            cols += min(data1[j],data2[j])
        return "%dA%dB" %(bulls,cols)

t = Solution()
print(t.getHint("1807","7810"))
print(t.getHint("1123","0111"))

