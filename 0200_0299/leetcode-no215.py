class Solution:
    def findKthLargest(self, nums: list[int], k: int) -> int:
        return sorted(nums,reverse=True)[k-1]

t = Solution()
print(t.findKthLargest([3,2,3,1,2,4,5,5,6],4))
print(t.findKthLargest([3,2,1,5,6,4],2))