class Solution(object):
    def check(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        length = len(nums)
        begin = length
        for i in range(length-1):
            if nums[i]>nums[i+1]:
                begin = i+1
                break
        if sorted(nums) == nums[begin:]+nums[:begin]:
            return True
        return False
t = Solution()
print(t.check([1]))
