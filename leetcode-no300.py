class Solution:
    def lengthOfLIS(self, nums: list[int]) -> int:
        total = 0
        start = []
        for i in range(1,len(nums)-1):
            if nums[i-1] < nums[i] < nums[i+1]:
                start.append(i)
        if len(nums)>=2:
            if nums[0] > nums[1]:
                pass


class Solution:
    def lengthOfLIS(self, nums: list[int]) -> int:
        if not nums:
            return 0
        dp = [0]*len(nums)
        for i in range(len(nums)):
            for j in range(i):
                if nums[j]<nums[i]:
                    dp[i] = max(dp[i],dp[j]+1)
        return max(dp)



