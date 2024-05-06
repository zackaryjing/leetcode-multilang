class Solution:
    def search(self, nums: list[int], target: int) -> bool:
        smallest = min(nums)
        pos = 0
        n = len(nums)
        for i in range(1,n):
            if nums[i] < nums[i-1]:
                pos = i
                break
        nums = nums[pos:] + nums[:pos]
        print(nums)
        left = 0
        right = n - 1
        # if right == 1:
        #     return target == nums[0]
        while left < right:
            mid = (left + right + 1) // 2
            print(left, mid, right)
            if nums[mid] == target:
                return True
            elif nums[mid] < target:
                left = mid
            else:
                right = mid - 1
        if nums[left] != target:
            return False
        return True

t = Solution()
print(t.search([2,2,2,0,2,2],0))
print(t.search([2,2,2,3,2,2,2],3))
print(t.search([1],0))
print(t.search([1,0,1,1,1],0))
print(t.search([2,5,6,0,0,1,2],0))
print(t.search([2,5,6,0,0,1,2],3))
