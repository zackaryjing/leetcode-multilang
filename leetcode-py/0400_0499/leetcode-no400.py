class Solution:
    def findNthDigit(self, n: int) -> int:
        a = h = 9
        k = 1
        while n > h:
            a *= 10
            k += 1
            h += a*k
        s = str(int("9"*k)-(h-n)//k)
        return s[k-(h-n)%k-1]


t = Solution()
print(t.findNthDigit(3000))
print(t.findNthDigit(1000))
print(t.findNthDigit(1001))
print(t.findNthDigit(1002))
print(t.findNthDigit(100))
print(t.findNthDigit(1))
