class Solution:
    def fib(self, n: int) -> int:
        t = 1
        a = 1
        b = 1
        while t != n:
            a,b = b,a+b
            t += 1
        return a
t = Solution()
print(t.fib(4))
print(t.fib(7))

