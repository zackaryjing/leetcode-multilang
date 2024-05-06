class Solution2(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        b = set(nums)
        return (set([i for i in range(len(nums)+1)])-b).pop()

class Solution(object):
    def missingNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        for i in range(len(nums)+1):
            try :
                nums.remove(i)
            except:
                return i

class Solution(object):
    def missingNumber(self, nums):
        length = len(nums)
        nums.sort()
        for i in range(length):
            if not i == nums[i]:
                return i
        return length


t = Solution()
print(t.missingNumber([1,0,3,4,2,6]))