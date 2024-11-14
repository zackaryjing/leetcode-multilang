class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        a = "0b"+a
        b = "0b"+b
        return str(bin(eval(a)+eval(b)))[2:]

t = Solution()
print(t.addBinary("11","1"))