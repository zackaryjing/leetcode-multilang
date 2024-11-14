class Solution2(object):
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        #随手来个递归解法吧
        """
        执行用时：16 ms, 在所有 Python 提交中击败了97.26%的用户
        内存消耗：13.3 MB, 在所有 Python 提交中击败了5.02%的用户
        """
        def getsum(num):
            if num < 10:
                return num
            num = str(num)
            k = map(int,list(num))
            sum = 0
            for j in k:
                sum += j
            return getsum(sum)
        return getsum(num)


class Solution(object):
    def addDigits(self, num):
        """
        :type num: int
        :rtype: int
        """
        #循环版本
        while num >= 10:
            num = str(num)
            k = map(int,list(num))
            num = 0
            for j in k:
                num += j
        return num


'''
看了一些大神的解法，感觉这题确实可以更简单
'''
class Solution(object):
    def addDigits(self, num):
        return (num-1) % 9 + 1 if num != 0 else 0

t = Solution()
print(t.addDigits(0))