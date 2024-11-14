class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        h = 0
        for i in nums:
            t = target-i
            try:
                a = nums.index(t)
                if a != h:
                    return [h,a]
            except:
                pass
            h += 1
