from configparser import ConfigParser

class Solution2(object):
    def threeSum(self,nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        def twosum(target,alist):
            left = 0
            right = len(alist)-1
            middleresult = []
            while left < right:
                if alist[left]+alist[right] >target:
                    right -= 1
                else:
                    if alist[left]+alist[right] == target:
                        middleresult.append([alist[left],alist[right]])
                    left += 1
            return middleresult
        result = []
        processed = []
        nums = sorted(nums)
        for i in nums:
            if i in processed:
                continue
            else:
                processed.append(i)
            minorNum = nums[:]
            minorNum.remove(i)
            for t in twosum(-i,minorNum):
                each = [i]
                each.extend(t)
                each = sorted(each)
                if not each == [i] and not(each in result):
                    result.append(each)
        return result   


class Solution(object):   #上一个做法慢到离谱，其实是twosum函数不够高效
    def threeSum(self,nums):  #结论是修改的twosum方法更慢了
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        def twosum(target,alist):
            middleresult = []
            for i in alist:
                minoralist = alist[:]
                minoralist.remove(i)
                pear = target - i
                two = sorted([i,pear])
                if pear in minoralist and not (two in middleresult):
                    middleresult.append(two)
            return middleresult
        result = []
        processed = []
        nums.sort()
        for i in nums:
            if i in processed:
                continue
            else:
                processed.append(i)
            minorNum = nums[:]
            minorNum.remove(i)
            for t in twosum(-i, minorNum):
                each = [i]
                each.extend(t)
                each = sorted(each)
                if not each == [i] and not(each in result):
                    result.append(each)
        return result

class Solution:       #偷一波别人的代码研究研究
    def threeSum(self, nums):
        ans = []
        n = len(nums)
        nums.sort()
        for i in range(n):
            left = i + 1
            right = n - 1
            if nums[i] > 0:
                break
            if i >= 1 and nums[i] == nums[i - 1]:
                continue
            while left < right:
                total = nums[i] + nums[left] + nums[right]
                if total > 0:
                    right -= 1
                elif total < 0:
                    left += 1
                else:
                    ans.append([nums[i], nums[left], nums[right]])
                    while left != right and nums[left] == nums[left + 1]: left += 1
                    while left != right and nums[right] == nums[right - 1]: right -= 1
                    left += 1
                    right -= 1
        return ans

CONFIGFILE = "tests.txt"
t = Solution2()
config = ConfigParser()
config.read(CONFIGFILE)
h = eval(config.get("threesum",'test1'))
print(t.threeSum(h))


