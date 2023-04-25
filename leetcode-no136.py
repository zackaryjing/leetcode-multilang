class Solution3(object): #最慢的做法
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        for i in nums:
            if nums.count(i) == 1:
                return i

class Solution2(object): #比3快5倍
    def singleNumber(self, nums):
        left = []
        for i in nums:
            if not i in left:
                left.append(i)
            else:
                left.remove(i)
        return left[0]

class Solution(object):  #目前我最快的算法
    def singleNumber(self, nums):
        nums.sort()
        for i in range(0,len(nums)-1,2):
            if nums[i] != nums[i+1]:
                if nums.count(nums[i]) == 1:
                    return nums[i]
                else:
                    return nums[i+1]
        return nums.pop()

class Solution1(object):
    def singleNumber(self, nums):
        nums.sort()
        for i in range(0,len(nums)-2,2):
            if nums[i] != nums[i+1]:
                return nums[i]
        return nums.pop()


class Solution(object):   #奇妙的异或运算，可以满足结合律
    def singleNumber(self, nums):
        a = 0
        for num in nums:
            a = a ^ num
        return a

# for i in range(0,3,2):
#     print(i)
# t = Solution()
# print(t.singleNumber([1,1,2]))

print()