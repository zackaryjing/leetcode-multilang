class Solution2(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        result = 1
        i = 0
        if x == 1:
            return 1
        if x == -1:
            return x ** (n % 2)
        if n >= 0:
            while i < n:
                if abs(result) <= 0.00001:
                    return 0
                result *= x
                i += 1
        else:
            while i < abs(n):
                if abs(result) <= 0.00001:
                    return 0
                result /= x
                i += 1
        return result


class Solution(object):
    def myPow(self, x, n):
        return x**n

t = Solution()
print(t.myPow(2,-1))
print(t.myPow(0.00001,2147483647))