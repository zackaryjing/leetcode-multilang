from itertools import permutations
class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result = []
        [result.append(i) for i in permutations(nums) if not i in result]
        return result

t = Solution()
print(t.permute([1,1,3]))