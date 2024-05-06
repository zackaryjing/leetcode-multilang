class Solution(object):
    def isPowerOfTwo(self, n):
        """
        :type n: int
        :rtype: bool
        """
        return True if bin(n).count('1')==1 and n>0 else False

t = Solution()
print(t.isPowerOfTwo(-256))