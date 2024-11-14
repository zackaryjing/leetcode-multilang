class Solution:
    def judgeSquareSum(self, c: int) -> bool:
        a = 0
        b = int(c**0.5)
        while a <= b:
            current = a ** 2 + b ** 2
            if current == c:
                return True
            if current < c:
                a += 1
            if current > c:
                b -= 1
        return False
t = Solution()
print(t.judgeSquareSum(5))
