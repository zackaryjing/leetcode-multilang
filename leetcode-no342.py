class Solution(object):
    def isPowerOfFour(self, n):
        """
        :type n: int
        :rtype: bool
        """
        while n >= 4 and n%4 == 0:
            n /= 4
        if n == 1:
            return True
        return False

t = Solution()
print(t.isPowerOfFour(100))