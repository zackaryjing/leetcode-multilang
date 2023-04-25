

class Solution(object):
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        if nums == []:
            return []
        result = []
        length = len(nums)
        cache = []
        j = -1
        for j in range(length - 1):
            cache.append(nums[j])
            if nums[j] != nums[j + 1] - 1:
                if len(cache) == 1:
                    result.append(str(cache[0]))
                else:
                    result.append(str(cache[0]) + "->" + str(cache.pop()))
                cache = []
        cache.append(nums[j + 1])
        if len(cache) == 1:
            result.append(str(cache[0]))
        else:
            result.append(str(cache[0]) + "->" + str(cache.pop()))
        return result


class Solution2(object):
    def summaryRanges(self, nums):
        #先分片
        if nums == []:
            return []
        result = []
        length = len(nums)
        cache = []
        j = -1
        for j in range(length - 1):
            cache.append(nums[j])
            if nums[j] != nums[j+1]-1:
                result.append(cache)
                cache = []
        cache.append(nums[j+1])
        result.append(cache)
        end = []
        for t in result:
            if len(t) == 1:
                end.append(str(t[0]))
            else:
                end.append(str(t[0])+"->"+str(t.pop()))
        return end
t = Solution()
print(t.summaryRanges([0,2,3,4,6,8,9,11]))
