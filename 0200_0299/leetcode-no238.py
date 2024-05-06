from functools import reduce
class Solution:
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        nums2 = [1 if i == 0 else i for i in nums]
        n = len(nums)
        a = reduce(lambda x,y:x*y,nums2)
        for i in range(n):
            if nums[i] == 0:






t = Solution()
print(t.productExceptSelf([1,2,3]))
print(t.productExceptSelf([0,2,3]))
