from math import factorial as fac
class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        #定义排列组合数
        def combaination(a,b):
            return fac(b)//(fac(a)*fac(b-a))
        sum = 0
        for i in range(n//2+1):
            sum += combaination(i,n-i)
        return sum

class Solution2(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        #定义排列组合数
        sum = 0
        for i in range(n//2+1):
            sum += fac(n-i)//(fac(i)*fac(n-2*i))
        return sum
t = Solution2()
print(t.climbStairs(6))
