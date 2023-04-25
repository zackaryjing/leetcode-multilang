"""
我的解法不可用，在nums较小的情况下可以返回有效答案
但是当nums过大时往往会偏大。
在查看题解后了解到可以使用二分法来解题
我的算法失误的根本原因在于nums中小于理论最小值的
数字是不可以再拆分的,这一部分的信息被忽视了。
"""

from math import ceil

# 二分解法
class Solution:
    def minimumSize(self, nums: list[int], maxOperations: int) -> int:
        left, right, ans = 1,max(nums),0
        while left <= right:
            mid = (left + right) // 2
            ops = sum((x-1) // mid for x in nums)
            if ops <= maxOperations:
                ans = mid
                right = mid - 1
            else:
                left = mid + 1
        return ans



class Solution:
    def minimumSize(self, nums: list[int], maxOperations: int) -> int:
        minum = ceil(sum(nums) / (maxOperations + len(nums)))
        valid = [i for i in nums if i > minum]
        minum = ceil(sum(nums) / (len(valid) + maxOperations))
        while maxOperations:
            maxum = max(nums)
            nums.remove(maxum)
            nums.extend([minum,maxum-minum])
            maxOperations -= 1
        print(nums)
        return max(nums)

t = Solution()
print(t.minimumSize([9],2))
print(t.minimumSize([2,4,8,2],4))
print(t.minimumSize([7,17],2))
print(t.minimumSize([431,922,158,60,192,14,788,146,788,775,772,792,68,143,376,375,877,516,595,82,56,704,160,403,713,504,67,332,26],80))
