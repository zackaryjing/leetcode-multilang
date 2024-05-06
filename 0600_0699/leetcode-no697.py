from collections import defaultdict
class Solution(object):
    def findShortestSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        data = defaultdict(int)
        for i in nums:
            data[i] += 1
        values = data.values()
        biggest = max(values)
        candidates = [k for k,v in data.items() if v == biggest]
        length = len(nums)
        return min([length-nums.index(h)-list(reversed(nums)).index(h) for h in candidates])

t = Solution()
print(t.findShortestSubArray([1,1,2,2,2,2,4,4,4,4,5,2]))
