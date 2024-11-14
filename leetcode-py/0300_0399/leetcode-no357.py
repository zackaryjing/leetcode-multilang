from typing import *
from functools import reduce

class Solution1:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        num = str(n)
        used = set()
        n = len(num)
        ans = 0
        def getend(x):
            res = 1
            for i in range(11-n,12-x):
                res *= i
            return res
        
        print(getend(2))
        # for i in range(n):
            # if i == 0:
            #     ans += int(num[i])*

class Solution2:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        num = str(n)
        length = len(num)
        ans = 0
        def getback(pos):
            tmp = 1
            for h in range(11-length,11-pos):
                tmp *= h
            return tmp
        used = set()
        for i in range(length):
            if i != 0:
                cur = len(set(range(0,int(num[i]))) - used) - 1
            else:
                cur = int(num[i]) - 1
            ans += cur * getback(i+1)
            used.add(int(num[i]))
        return ans
    



class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        if n == 0:
            return 1
        cur = 9
        ans = 10
        for i in range(1,n):
            # print(10-i)
            cur *= 10 - i
            ans += cur
        return ans
    
        
        
        

t = Solution()
print(t.countNumbersWithUniqueDigits(0))
print(t.countNumbersWithUniqueDigits(1))
print("-"*40)
print(t.countNumbersWithUniqueDigits(2))
print("-"*40)
print(t.countNumbersWithUniqueDigits(3))
print("-"*40)
print(t.countNumbersWithUniqueDigits(4))
print("-"*40)
print(t.countNumbersWithUniqueDigits(7))
print("-"*40)
print(t.countNumbersWithUniqueDigits(8))
print("-"*40)

# n = 3
# print(reduce(lambda x,y:x*y,range(9,9-n+1,-1)))







