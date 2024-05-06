class Solution(object):
    def sortColors(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        a = nums.count(0)
        b = nums.count(1)
        c = nums.count(2)
        del nums[:]
        nums += ([0]*a + [1]*b + [2]*c)
        return nums

class Solution2(object):
    def sortColors(self, nums):
        a = nums.count(0)
        length = len(nums)
        c = nums.count(2)
        del nums[:]
        nums.extend([0]*a + [1]*(length-a-c) + [2]*c)
        return nums

t = Solution()
print(t.sortColors([2,1,0,0,0,1,1,1,2,2,0]))