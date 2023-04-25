class Solution2(object):
    def isPowerOfThree(self, n):
        """
        :type n: int
        :rtype: bool
        """
        alist = [1,3,9,27,81,243,729,2187,6561,19683,59049,177147,531441,1594323,4782969,14348907,43046721,129140163,387420489,1162261467,3486784401]
        return n in alist

class Solution(object):
    def isPowerOfThree(self, n):
        """
        :type n: int
        :rtype: bool
        """
        return 3486784401%n == 0 if n!= 0 else False

t = Solution()
print(t.isPowerOfThree(0))

