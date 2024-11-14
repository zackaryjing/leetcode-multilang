class Solution2(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        n = nums.count(0)
        for i in range(n):
            nums.remove(0)
        nums.extend([0]*n)
        return nums

class Solution(object):
    def moveZeroes(self, nums):
        a=''.join(map(str,nums))
        b = a.replace('0','')
        b = b + '0'*(len(a)-len(b))
        nums = map(int,list(b))
        return [i for i in nums]


t = Solution()
print(t.moveZeroes([1,2,0,3,0,0,4]))