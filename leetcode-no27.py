class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        times = nums.count(val)
        for i in range(0,times):
            nums.remove(val)
        return len(nums)