class Solution(object):
    def mySqrt(self, x):
        """
        :type x: int
        :rtype: int
        """
        root = 0.5 * x
        if x < 1:
            return 0
        def square(x,root):
            last = root
            root = 0.5*(root + x/root)
            if int(root) != int(last):
                return square(x,root)
            return root
        return int(square(x,root))

t = Solution()
print(t.mySqrt(8))