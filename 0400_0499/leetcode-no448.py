class Solution(object):
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        length = len(nums)
        result = []
        for i in range(1,length+1):
            if not i in nums:
                result.append(i)
        return result
class Solution(object):
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        t = set([i for i in range(1,len(nums)+1)])
        b = set(nums)
        return list(t-b)

t = Solution()
print(t.findDisappearedNumbers([1,1]))
