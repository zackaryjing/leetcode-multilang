class Solution2:
    def singleNumber(self, nums: list[int]) -> list[int]:
        if len(nums) <= 2:
            return nums
        nums.sort()
        t = zip(nums[1:],nums[2:],nums)
        res = []
        resn = 0
        for i in t:
            if not (i[0] == i[1] or i[1] == i[2] or i[0] == i[2]):
                resn += 1
                res.append(i[0])
                if resn == 2:
                    break
        if resn == 0:
            res += [nums[0],nums[-1]]
        if resn == 1:
            if nums[0] == nums[1]:
                res.append(nums[-1])
            else:
                res.append(nums[0])
        return res

class Solution:
    def singleNumber(self, nums: list[int]) -> list[int]:
        n = len(nums)
        if n <= 2:
            return nums
        nums.sort()
        res = []
        i = 0
        while i < n - 1:
            if nums[i] != nums[i+1]:
                res.append(nums[i])
                res += 1
                if res >= 2:
                    break
                i += 1
            else:
                i += 2
        if i == n-1:
            res.append(nums[-1])
        return res


"""
[3, 5]
[2, 4]
[1, 5]
[1]
"""
t = Solution()
print(t.singleNumber([1,2,1,3,2,5]))
print(t.singleNumber([1,1,2,3,3,4,5,5]))
print(t.singleNumber([1,5]))
print(t.singleNumber([1]))




