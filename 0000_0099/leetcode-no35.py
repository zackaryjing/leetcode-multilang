class Solution2(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        try:
            return nums.index(target)
        except:
            length = len(nums)
            for i in range(-1,length):
                try:
                    if target <= nums[i+1]:
                        return i+1
                except:
                    return i+1


class Solution(object):
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.append(target)
        nums.sort()
        return nums.index(target)

t = Solution()
print(t.searchInsert([1,3,5,6],5))