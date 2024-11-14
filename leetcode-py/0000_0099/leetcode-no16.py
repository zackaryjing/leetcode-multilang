class Solution:
    def threeSumClosest(self, nums: list[int], target: int) -> int:
        nums.sort()
        # print(nums)
        n = len(nums)
        minum = target - nums[0] - nums[1] - nums[-1]
        ans = nums[0] + nums[1] + nums[-1]
        for i in range(n-2):
            first = nums[i]
            left = i + 1
            right = n - 1
            target2 = target - first
            while left < right:
                # print(first,nums[left], nums[right])
                if abs((temp := (target2 - nums[left] - nums[right]))) < abs(minum):
                    minum = temp
                    ans = first + nums[left] + nums[right]
                # print("here", temp)
                if temp < 0:
                    # print("move left")
                    right -= 1
                else:
                    # print("move right")
                    left += 1
        return ans

t = Solution()
print(t.threeSumClosest([-1,2,1,-4],1))
print(t.threeSumClosest([1,1,1,0],-100))
print(t.threeSumClosest([4,0,5,-5,3,3,0,-4,-5],-2))



