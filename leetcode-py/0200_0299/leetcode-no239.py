from typing import *
from collections import deque
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        window = deque()
        cur = 0
        ans = []
        while cur < n:
            while window and window[-1][0] <= nums[cur]:
                window.pop()
            window.append((nums[cur],cur))
            if window[0][1] <= cur - k:
                window.popleft()
            if cur >= k - 1:
                ans.append(window[0][0])
            cur += 1
        
        return ans
    
t = Solution()
print(t.maxSlidingWindow([1,3,-1,-3,5,3,6,7],3))







        