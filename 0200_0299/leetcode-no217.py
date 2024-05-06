class Solution2(object):
    def containsDuplicate(self, nums):
        nums.sort()
        for i in range(len(nums)-1):
            if nums[i] == nums[i+1]:
                return True
        return False

class Solution(object):
    def containsDuplicate(self, nums):
        nums.sort()
        length = len(nums)
        i = 0
        b = ''
        while i < length:
            a = nums[i]
            if a == b:
                return True
            i += 1
            b = a
        return False

class Solution(object):
    def containsDuplicate(self, nums):
        nums2 = nums[:]
        for i in nums2:
            nums.remove(i)
        return False
t = Solution()
print(t.containsDuplicate([1,2,3,1]))