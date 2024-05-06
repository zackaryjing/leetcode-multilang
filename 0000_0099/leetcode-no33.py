class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        t = 0
        for i in nums:
            if i == target:
                return t
            t += 1
        return -1