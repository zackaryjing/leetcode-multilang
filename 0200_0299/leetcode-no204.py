class Solution2(object):
    def countPrimes(self, n): #超时了
        """
        :type n: int
        :rtype: int
        """
        def isprime(num):
            k = int(num**0.5) +1
            for i in range(2,k):
                if num % i == 0:
                    return False
            return True
        if n == 1 or n==0 or n == 2:
            return 0
        if n == 3:
            return 1
        time = 1
        result = []
        for j in range(3,n,2):
            if isprime(j):
                result.append(j)
        return result

class Solution(object):
    def countPrimes(self, n):
        """
        :type n: int
        :rtype: int
        """
        def isprime(num):
            k = num**0.5+1
            for i in primes:
                if i >= k:break
                if num % i == 0:
                    return False
            return True
        primes = []
        # time = 0
        for j in range(2,n):
            if isprime(j):
                primes.append(j)
                # time += 1
        return primes

t = Solution()

from timeit import *
# print(t.countPrimes(0))
# print(t.countPrimes(1))
# print(t.countPrimes(2))
# print(t.countPrimes(3))
# print(t.countPrimes(179765))
# def test1():
#     t.countPrimes(1500000)
#
# s = Solution2()
# def test2():
#     s.countPrimes(1500000)
#
#
# t1 = Timer("test1()","from __main__ import test1")
# print(t1.timeit(number=1))
# t2 = Timer("test2()","from __main__ import test2")
# print(t2.timeit(number=1))
t = Solution2
print(t.countPrimes())