from typing import *
from collections import deque
import heapq

class Solution:
    def kSmallestPairs(self, nums1: List[int], nums2: List[int], k: int) -> List[List[int]]:
        m, n = len(nums1),len(nums2)
        ans = []
        pq = [(nums1[i] + nums2[0],i,0) for i in range(min(k,m))]
        print(pq)
        while pq and len(ans) < k:
            _,i,j = heapq.heappop(pq)
            # print(_,i,j)
            print(pq,i,j)
            ans.append([nums1[i],nums2[j]])
            if j + 1 < n:
                heapq.heappush(pq,(nums1[i] + nums2[j + 1], i, j + 1))
        return ans
        
t = Solution()
print(t.kSmallestPairs([1,7,11],[2,4,6],3))

    
    