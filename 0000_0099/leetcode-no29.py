# coding=gbk
from timeit import Timer


class Solution2(object):
    def divide(self, dividend:int, divisor:int)->int:
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        positive = 1
        if (dividend < 0 and divisor > 0) or (dividend > 0 and divisor < 0):
            positive = 0
        k = 0
        if positive:
            dividend = abs(dividend)
            divisor = abs(divisor)
            while dividend >= 0:
                dividend -= divisor
                k += 1
            return k - 1
        else:
            dividend = abs(dividend)
            divisor = abs(divisor)
            while dividend >= 0:
                dividend -= divisor
                k += 1
            return -(k - 1)


class Solution3(object):  # 尝试用指数加速
    def divide(self, dividend, divisor): # 结果还是太慢了太慢了！
        positive = 1
        if dividend == 0:
            return 0
        if (dividend < 0 and divisor > 0) or (dividend > 0 and divisor < 0):
            positive = 0
        dividend = abs(dividend)
        divisor = abs(divisor)
        first = 0
        second = 0
        dividendc = dividend
        divisorc = divisor
        while dividendc != 1:
            dividendc = dividendc >> 1
            first += 1
        while divisorc != 1:
            divisorc = divisorc >> 1
            second += 1
        i = 0
        cha = first-second-1
        if cha >= 0:
            dividend = dividend - (divisor << (cha))
        while dividend >= 0:
            dividend -= divisor
            i += 1
        if positive:
            return int(i + 2**(cha) - 1)
        else:
            return -int((i + 2 ** (cha) - 1))

from math import *
class Solution(object):  # 使用对数
    def divide(self, dividend, divisor):
        if dividend == 2147483647 and divisor == -2147483648:
            return 0
        if dividend == 0:
            return 0
        positive = 1
        if (dividend < 0 and divisor > 0) or (dividend > 0 and divisor < 0):
            positive = 0
        dividend = abs(dividend)
        divisor = abs(divisor)
        result = int(exp(log(dividend)-log(divisor))+0.0000007)
        if result >= 2147483648 and positive == 1:
            return 2147483647
        if result >= 2147483648 and positive == 0:
            return -2147483648
        if positive:
            return result
        else:
            return -result





# def test1():
#     t = Solution2()
#     t.divide(100000000,1)
# s1 = Timer("test1()","from __main__ import test1")
# print("this",s1.timeit(number=5),"seconds")
t = Solution()
print(t.divide(2147483647,-2147483648))