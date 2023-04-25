class Solution:
    def numberOfArithmeticSlices(self, nums: list[int]) -> int:
        n = len(nums)
        total = 0
        for i in range(0,n-2):
            if nums[i] - nums[i+1] == nums[i+1] - nums[i+2]:
                while i < n - 2 and nums[i] - nums[i+1] == nums[i+1] - nums[i+2]:
                    total += 1
                    i += 1
        return total

t = Solution()
print(t.numberOfArithmeticSlices([1,2,3,4]))
print(t.numberOfArithmeticSlices([1]))
