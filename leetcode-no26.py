class Solution1(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        last = 't'
        t = 0
        for i in range(0,len(nums)):
            if nums[i] != last:
                last = nums[i]
            else:
                nums[i] = 'a'
                t += 1
        print(nums)
        for i in range(0,t):
            nums.remove('a')
        return len(nums)

class Solution2(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        num = nums[:]
        for i in num:
            if nums.count(i) > 1:
                nums.remove(i)
        return len(nums)

class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
         
t=Solution()
print(t.removeDuplicates([1,1,1,1,1,1]))