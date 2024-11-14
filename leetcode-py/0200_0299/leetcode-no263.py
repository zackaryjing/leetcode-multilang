class Solution2(object):
    def isUgly(self, n):
        """
        :type n: int
        :rtype: bool
        """
        #随手写一个暴力解法
        n = abs(n)
        for i in range(2,n):
            if n%i == 0:
                if not(i%2 == 0 or i%3 == 0 or i%5 == 0):
                    return False
        return True
        #针对大数还是太慢了

class Solution(object):
    def isUgly(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if n <= 0:
            return False
        while n % 2 == 0:
            n //= 2
        while n % 3 == 0:
            n //= 3
        while n % 5 == 0:
            n //= 5
        if not n == 1:
            return False
        else:
            return True
'''
对于一个大于5的数如果没有235之一的因子，一定是丑数

'''
t = Solution()
print(t.isUgly(-2147483648))