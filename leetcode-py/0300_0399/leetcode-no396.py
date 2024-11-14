class Solution(object):
    def maxRotateFunction(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        """
        没什么问题，但是超时了
        """
        length = len(nums)
        result = []
        for i in range(length):
            sum = 0
            for j in range(-i,length-i):
                sum += (j+i)*nums[j]
            result.append(sum)
        return max(result)

class Solution(object):
    def maxRotateFunction(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        f,n,numSum = 0,len(nums),sum(nums)
        for i,num in enumerate(nums):
            f += i*num
        res = f
        for i in range(n-1,0,1):
            f = f+numSum - n*nums[i]
            res = max(res,f)
        return res


t = Solution()
print(t.maxRotateFunction([4,3,2,6]))

