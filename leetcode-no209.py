from itertools import accumulate
class Solution:
    def minSubArrayLen(self, target: int, nums: list[int]) -> int:
        start = end = 0
        data = [0] + list(accumulate(nums))
        n = len(data)
        minum = float('inf')
        while end < n:
            if data[end] - data[start] >= target:
                if (end - start) < minum:
                    minum = end - start
                start += 1
            else:
                end += 1
        return minum if not minum == float('inf') else 0

t = Solution()
print(t.minSubArrayLen(7,[2,3,1,2,4,3]))
print(t.minSubArrayLen(11,[1,1,1,1,1,1,1,1]))


