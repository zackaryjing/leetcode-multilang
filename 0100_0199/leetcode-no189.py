class Solution:
    def rotate(self, nums: list[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        k %= n
        a = nums[0:n-k]
        del nums[0:n-k]
        nums.extend(a)
        return nums

t = Solution()
print(t.rotate([1,2,3,4,5,6,7],3))
print(t.rotate([1,2,3,4,5,6,7],0))
print(t.rotate([1,2,3,4,5,6,7],8))
