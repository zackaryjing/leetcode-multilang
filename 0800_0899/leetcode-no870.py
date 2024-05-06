from typing import *
class Solution:
    def advantageCount(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nums1.sort()
        n = len(nums1)
        # print(nums2)
        # print(list(enumerate(nums2)))
        nums2 = sorted(list(enumerate(nums2)),key = lambda x:x[1])
        # print(nums2)
        left = right = 0
        ans = [0] * n
        notused = []
        while left < n:
            if nums1[left] > nums2[right][1]:
                ans[nums2[right][0]] = nums1[left]
                left += 1
                right += 1
            else:
                notused.append(nums1[left])
                left += 1
        for j in range(right,n):
            ans[nums2[j][0]] = notused[j-right]
        return ans
    
t = Solution()
print(t.advantageCount([2,7,11,15],[1,10,4,11]))
print(t.advantageCount([12,24,8,32], [13,25,32,11]))





# print(list(enumerate([1,10,3,11])))