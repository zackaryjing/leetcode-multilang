class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        num = 0
        times = 0
        for i in digits[::-1]:
            num += 10**times * i
            times += 1
        return [int(i) for i in str(num+1)]
t = Solution()
print(t.plusOne([1,2,3]))