from functools import cache
class Solution2:
    def majorityElement(self, nums: list[int]) -> list[int]:
        n = len(nums) // 3
        @cache
        def count(num):
            nonlocal nums
            return nums.count(num)
        for i in set(nums):
            count(i)
        nums.sort(key=count,reverse=True)
        res = []
        a = set(nums)
        print(nums,a)
        for i in range(2):
            if a:
                c = a.pop()
                if count(c) > n:
                    res.append(c)
        return res

class Solution:
    def majorityElement(self, nums: list[int]) -> list[int]:
        nums.sort()
        n = len(nums)
        if n < 3:
            return list(set(nums))
        slow = 0
        fast = n // 3
        res = set()
        while fast < n:
            if nums[slow] == nums[fast]:
                res.add(nums[slow])
            fast += 1
            slow += 1
        return list(res)


t = Solution()

print(t.majorityElement([2,2]))
print(t.majorityElement([3,2,3]))
print(t.majorityElement([1,1,1,2,2,3]))
print(t.majorityElement([1,3,3,2,2,4,3,3,5,5,6,3,3,7,7]))

