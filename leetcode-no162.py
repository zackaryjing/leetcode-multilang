class Solution(object):
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        length = len(nums)
        if length == 0:
            return None
        if length <= 2:
            return max(nums)
        result = 0
        for i in range(1,length-1):
            if nums[i] > nums[i+1] and nums[i] > nums[i-1]:
                result = i
                break
        return result


t = Solution()
print(t.findPeakElement([1,2,1,3,4,5,4,1,2,1]))