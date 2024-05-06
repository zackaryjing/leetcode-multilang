class Solution:
    def findMedianSortedArrays(self, nums1: list[int], nums2: list[int]) -> float:
        nums = nums1 + nums2
        nums.sort()
        length = len(nums)
        if length % 2:
            return nums[length // 2]
        else:
            return (nums[length // 2] + nums[length // 2 - 1]) / 2

t = Solution()
print(t.findMedianSortedArrays([1,3],[2]))
print(t.findMedianSortedArrays([1,2],[3,4]))
