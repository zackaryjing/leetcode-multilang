class Solution(object):
    def nextPermutation(self, nums): #消耗的内存还是太多了
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        if nums == []:
            return nums
        length = len(nums)
        ends = []
        intervalBegin = -1
        ends.append(nums[length-1])
        for i in range(length-2,-1,-1):
            ends.append(nums[i])
            if nums[i] < nums[i+1]:
                intervalBegin = i
                break
        if intervalBegin == -1:
            print(sorted(nums))
            return nums.sort()
        for t in ends:
            if t > nums[intervalBegin]:
                nums[intervalBegin] = t
                ends.remove(t)
                break
        nums[intervalBegin+1:] = sorted(ends)
        return nums

t = Solution()
print(t.nextPermutation([1,9,7,2,5,4,3,1]))
print(t.nextPermutation([1,2,3]))
print(t.nextPermutation([4,3,2,1]))
print(t.nextPermutation([3,2,1]))
print(t.nextPermutation([1]))