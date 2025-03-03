class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        if x >= 0:
            t = int(str(abs(x))[::-1])
            if t < 2147483648:
                return t
        else:
            t = -int(str(abs(x))[::-1])
            if -2147483648 <= t:
                return t
        return 0


t = Solution()
print(t.reverse(-1200))
