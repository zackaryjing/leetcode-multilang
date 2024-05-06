class Solution(object):
    def hammingWeight(self, n):
        """
        :type n: int
        :rtype: int
        """
        return bin(n).count("1")

t = Solution()
print(t.hammingWeight(52))
print(bin(52))