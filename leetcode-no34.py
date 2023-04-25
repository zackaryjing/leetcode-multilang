class Solution:
    def searchRange(self, nums: list[int], target: int) -> list[int]:
        left = 0
        right = len(nums)-1
        mid = (left + right) // 2
        if not target in nums:
            return [-1,-1]
        while nums[mid] != target:
            if nums[mid] > target:
                right = mid
            else:
                left = mid
            mid = (left + right) // 2
        leftright = rightleft = mid
        leftmid = (leftright + left) // 2
        rightmid = (rightleft + right) // 2
        print(left,mid,right)
        while left != leftmid:
            if nums[leftmid] == target:
                leftright = leftmid
            else:
                left = leftmid
            leftmid = (leftright + left) // 2
        while rightleft != rightmid:
            print(rightleft,rightmid,right,"***)(")
            if nums[rightmid] == target:
                rightleft = rightmid
            else:
                right = rightmid
            rightmid = (rightleft + right) // 2
        res = []
        if nums[left] == target:
            res.append(left)
        elif nums[leftright] == target:
            res.append(leftright)
        if nums[right] == target:
            res.append(right)
        elif nums[rightmid] == target:
            res.append(rightmid)
        return res

class Solution:
    def searchRange(self, nums: list[int], target: int) -> list[int]:
        if not target in nums:
            return [-1,-1]
        else:
            res = []
            res.append(nums.index(target))
            res.append(len(nums)-list(reversed(nums)).index(target)-1)
            return res
t = Solution()
print(t.searchRange([5,7,7,8,8,10],8))
print(t.searchRange([1,4],4))
print(t.searchRange([5,7,10],6))
print(t.searchRange([5,5,5,5,7,7,7,7,8,8,8,10,11,11,13,14],8))
print(t.searchRange([5,5,5,5,7,7,7,7,8,10,11,11,13,14],8))
print(t.searchRange([7,7,8,8,8,8,8,8,8,8,8,8,8,8,8,8,8,9],7))

'''
7 9 11
9 10 11 ***)(
7
8 9

7 9 11
9 10 11 ***)(
7
8 9
None
'''