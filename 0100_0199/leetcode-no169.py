class Solution1(object):
    def majorityElement(self, nums): #内存小但速度慢
        """
        :type nums: List[int]
        :rtype: int
        """
        half = len(nums)//2+1
        front = nums[0:half]
        behind = nums[half:]
        candidate = nums[0:1]
        for i in front:
            if i in behind:
                candidate.append(i)
        for j in candidate:
            if nums.count(j) >= half:
                return j

class Solution2(object):          #速度似乎更慢了
    def majorityElement(self, nums):
        half = len(nums)/2
        for i in nums:
            if nums.count(i)>half:
                return i

class Solution3(object):      #速度还行，内存有点糟糕
    def majorityElement(self, nums):
        candidates = nums[0:1]
        length = len(nums)
        half = length/2
        if nums[length-1] == nums[0]:
            candidates.append(nums[0])
        if length > 1:
            a = nums[0]
            b = nums[1]
            for i in range(2,length+1):
                if (a == b) and not(b in candidates):
                    candidates.append(b)
                a = b
                try:
                    b = nums[i]
                except:
                    break
        for j in candidates:
            if nums.count(j) > half:
                return j

t = Solution()
print(t.majorityElement([6,5,5]))