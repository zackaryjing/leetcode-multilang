from collections import *
class Solution2(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        data = defaultdict(list)
        length = len(nums)
        for i in range(length):
            data[nums[i]].append(i)
        for j in data.values():
            leng = len(j)
            if leng>=2:
                for t in range(leng-1):
                    if j[t+1]-j[t]<=k:
                        return True
        return False

class Solution(object):  #滑动窗口写一波
    def containsNearbyDuplicate(self, nums, k):
        set = []
        length = len(nums)
        for i in range(length):
            each = nums[i]
            if i > k:
                del set[0]
            if not each in set:
                set.append(each)
            else:
                return True
        return False






t = Solution()
print(t.containsNearbyDuplicate([1,2,3,1,4,5,6,7,8,1],3))