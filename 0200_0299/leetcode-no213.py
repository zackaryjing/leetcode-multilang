class Solution:
    def rob(self, nums: list[int]) -> int:
        n = len(nums)
        if n == 1:
            return nums[0]
        elif n == 2:
            return max(nums)
        maxum = 0
        for j in [nums[1:], nums[:-1]]:
            premax = j[0]
            temp = j[1]
            for i in range(2, n - 1):
                premax, temp = max([premax, temp]), premax + j[i]
            if (t := max([premax, temp])) > maxum:
                maxum = t
        return maxum


t = Solution()
print(t.rob([1, 2, 3, 2, 6, 4, 5]))
