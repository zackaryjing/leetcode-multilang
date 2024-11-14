class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        largest = 0
        current = 0
        for i in nums:
            current = max(current+i,i)
            largest = current if current > largest else largest
        return largest

t = Solution()
print(t.maxSubArray([-2,1,-3,4,-1,2,1,-5,4]))
print(t.maxSubArray([5,4,-1,7,8]))
