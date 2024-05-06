class Solution(object):
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums = sorted(list(set(nums)))
        print(nums)
        return max(nums) if len(nums) <= 2 else nums[-3]

t = Solution()
print(t.thirdMax([-1,2,3]))