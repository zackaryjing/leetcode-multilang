class Solution:
    def maximumCount(self, nums: list[int]) -> int:
        neg = 0
        pos = 0
        for i in nums:
            if i < 0:
                neg += 1
            elif i > 0:
                pos += 1
        return max(neg,pos)

t = Solution()
print(t.maximumCount([-2,-1,-1,1,2,3]))
print(t.maximumCount([-3,-2,-1,0,0,1,2]))
print(t.maximumCount([5,20,66,1314]))
