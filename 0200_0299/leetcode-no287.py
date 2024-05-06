class Solution:
    def findDuplicate(self, nums: list[int]) -> int:
        nums.sort()
        k = list(set(nums))
        left = 0
        right = len(k) - 1
        while left < right:
            mid = (left + right + 1) // 2
            if nums[mid] < k[mid]:
                right = mid - 1
            else:
                left = mid
        return nums[right]

t = Solution()
print(t.findDuplicate([2,2,2,2]))
print(t.findDuplicate([1,3,4,2,2]))
print(t.findDuplicate([3,1,3,4,2]))
