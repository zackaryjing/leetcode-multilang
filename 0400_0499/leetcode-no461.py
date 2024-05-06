class Solution(object):
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        res = 0
        x = "%031d" %int(bin(x)[2:])
        y = "%031d" %int(bin(y)[2:])
        for i in range(31):
            if not x[i] == y[i]:
                res += 1
        return res

class Solution(object):
    def hammingDistance(self, x, y):
        """
        :type x: int
        :type y: int
        :rtype: int
        """
        h = x^y
        return bin(h).count("1")

t = Solution()
print(t.hammingDistance(5,6))