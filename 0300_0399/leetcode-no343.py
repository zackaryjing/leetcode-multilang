class Solution(object):
    def integerBreak(self, n):
        """
        :type n: int
        :rtype: int
        """
        # if n <= 2:
        #     return 1
        if n < 7:
            return [1, 2, 4, 6, 9][n - 2]
        nums = int(n/2.72)
        def f(nums):
            average = n//nums
            secondpart = n%nums
            return average**(nums-secondpart)*(average+1)**secondpart
        return max(f(nums),f(nums+1),f(nums-1))


t = Solution()
print(t.integerBreak(2))
print(t.integerBreak(3))
print(t.integerBreak(4))
print(t.integerBreak(5))
print(t.integerBreak(6))
print(t.integerBreak(7))
print(t.integerBreak(8))
print(t.integerBreak(10))
print(t.integerBreak(15))
print(t.integerBreak(27))
print(t.integerBreak(30))
'''
1
2
18
36
243
19683
59049
'''