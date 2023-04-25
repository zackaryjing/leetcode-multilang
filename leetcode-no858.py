class Solution:
    def mirrorReflection(self, p: int, q: int) -> int:
        start = 1
        while True:
            if q * start % p == 0:
                x = start
                y = q * start // p
                break
            start += 1
        if x % 2 == 0 and y % 2 == 0:
            return 3
        elif x % 2 == 0 and y % 2 != 0:
            return 2
        elif x % 2 != 0 and y % 2 == 0:
            return 0
        else:
            return 1

t = Solution()
print(t.mirrorReflection(2,1))
