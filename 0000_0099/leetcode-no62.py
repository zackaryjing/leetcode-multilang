class Solution2(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        def combianations(part,total):
            minor = min(part,total-part)
            result = 1
            for i in range(total,total-minor,-1):
                result *= i
            for j in range(1,minor+1):
                result //= j
            return result
        return combianations(m-1,m+n-2)

class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        total = m+n-2
        if n > m:
            n,m = m,n
        result = 1
        for i in range(total,m-1,-1):
            result *= i
        for j in range(1,n):
            result //= j
        return result


t = Solution()
print(t.uniquePaths(3,3))
