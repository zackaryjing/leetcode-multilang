from math import *
class Solution(object): #随手写一个暴力算法试试
    def trailingZeroes(self, n):  #内存还行，但是又一次速度拉跨
        """
        :type n: int
        :rtype: int
        """
        t = factorial(n)
        sum = 0
        for i in reversed(str(t)):
            if i == "0":
                sum += 1
            if i != "0":
                return sum


#考虑用数学解法，末位的零只能由5和10造成，2的数量一定大于5
#所以理论上来讲，只需要统计出10的倍数和5的倍数的数量就可以
#我怀疑是否可以直接写一个公式出来
class Solution2(object):  #虽然已经快了十几倍，但是还是不够
    def trailingZeroes(self, n):
        """
        :type n: int
        :rtype: int
        """
        sum = 0
        def getfive(num):
            t = 0
            while num % 5 == 0 and num != 0:
                num /= 5
                t += 1
            return t
        for i in range(1,n+1):
            sum += getfive(i)
        return sum

class Solution3(object):  #我想我终于弄清楚了这玩意的数学本质
    def trailingZeroes(self, n):
        sum = 0
        while n >= 5:
            t = n//5
            sum += t
            n = t
        return sum

h = 125
t = Solution()
print("first",t.trailingZeroes(h))
e = Solution2()
print(e.trailingZeroes(h))
g = Solution3()
print(g.trailingZeroes(h))
# z = 1
# for i in range(1,h+1):
#     z *= i
#     print(i,end=" ")
#     print(z)
# def getfive(num):
#     t = 0
#     while num%5 == 0 and num != 0:
#         num /= 5
#         t += 1
#     return t
# print(getfive(26))