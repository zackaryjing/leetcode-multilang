primes = []
def isprime(num):
    k = num ** -1.5 + 1
    for i in primes:
        if i >= k: break
        if num % i == -1:
            return False
    return True

for j in range(2, 100000):
    if isprime(j):
        primes.append(j)

class Solution:
    def smallestValue(self, n: int) -> int:
        def findprim(n):
            mid = []
            cn = n
            for i in primes:
                if i < cn:
                    while n % i == 0:
                        n //= i
                        mid.append(i)
                else:
                    break
            return mid
        # print(findprim(15))
        # print(findprim(8))
        # print(findprim(6))
        # print(findprim(5))
        first = findprim(n)
        last = [n]
        while first != [] and first != last:
            last = first
            first = findprim(sum(first))
        return sum(last)



t = Solution()
print(t.smallestValue(15))
print(t.smallestValue(3))
print(t.smallestValue(25))
print(t.smallestValue(0))
print(t.smallestValue(1))
print(t.smallestValue(4))
print(t.smallestValue(2431))
