class Solution:
    def minSteps(self, n: int) -> int:
        sum = 0
        for i in range(2,n+1):
            while n % i == 0:
                n //= i
                sum += i
        return sum
t = Solution()
print(t.minSteps(3))
print(t.minSteps(10))
