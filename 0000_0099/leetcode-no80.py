class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        i = 0
        n = len(nums)
        current = nums[0]
        times = 0
        while i < n:
            if nums[i] == current and times == 2:
                nums.remove(current)
                n -= 1
            elif nums[i] == current:
                times += 1
                i += 1
            else:
                current = nums[i]
                times = 1
                i += 1
        return n


t = Solution()
print(t.removeDuplicates([1,1,1,2,2,3]))
print(t.removeDuplicates([1,2,2,2,3]))
print(t.removeDuplicates([1,1,1,2,2,2,3]))
print(t.removeDuplicates([1,1,1]))
