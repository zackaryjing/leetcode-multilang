class Solution:
    def findDuplicates(self, nums: list[int]) -> list[int]:
        nums.sort()
        res = []
        length = len(nums)
        for i in range(length-1):
            if nums[i] == nums[i+1]:
                res.append(nums[i])
        return res
t = Solution()
print(t.findDuplicates([4,3,2,7,8,2,3,1]))

