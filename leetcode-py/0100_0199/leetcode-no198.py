class Solution(object): #原理没有问题，但是但是又双超时了
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        length = len(nums)
        results = []
        def jump(current,sum):
            if current >= length - 2:
                results.append(sum+nums[current])
            if current < length - 2:
                jump(current+2,sum+nums[current])
                if current < length - 3:
                    jump(current + 3, sum + nums[current])
        jump(0,0)
        if nums[1:]:
            jump(1,0)
        return max(results)

from collections import defaultdict
class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        length = len(nums)
        if length == 1:
            return nums[0]
        if length == 2:
            return max(nums[0],nums[1])
        data = defaultdict(set)
        data[0],data[1],data[2] = {nums[0]},{nums[1]},{nums[0]+nums[2]}
        for i in range(3,length):
            for j in data[i-3]:
                data[i].add(j+nums[i])
            for k in data[i-2]:
                data[i].add(k+nums[i])
        return max(max(data[length-2]),max(data[length-1]))

class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        length = len(nums)
        if length == 1:
            return nums[0]
        if length == 2:
            return max(nums[0],nums[1])
        data = defaultdict(set)
        data[0],data[1],data[2] = {nums[0]},{nums[1]},{nums[0]+nums[2]}
        for i in range(3,length):
            current = nums[i]
            for j in set.union(data[i-3],data[i-2]):
                data[i].add(j+current)
        return max(set.union((data[length-2]),data[length-1]))
t = Solution()
print(t.rob([0]))
print(t.rob([1,2,3,1]))
print(t.rob([1,2,3]))
print(t.rob([2,7,9,3,1,4,5,2,3]))