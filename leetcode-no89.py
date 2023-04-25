class Solution2(object):
    def grayCode(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        result = [0]
        for i in range(n):
            result += map(lambda x:x+2**i,reversed(result))
        return result

class Solution(object):
    def grayCode(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        res = []
        for i in range(2**n):
            res.append((i >> 1) ^ i)
        return res


t = Solution()
print(t.grayCode(2))
print(t.grayCode(3))
