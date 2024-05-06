from sortedcontainers import SortedList
# from sortedcontainers import SortedList
class Solution:
    def find132pattern(self, nums: list[int]) -> bool:
        # a = max(nums)
        # posa = nums.index(a)
        # b = min(nums[:a])
        n = len(nums)
        for i in range(1,n-1):
            if nums[i]>nums[i-1] and nums[i]>nums[i+1]:
                two = -float('inf')
                for j in range(i+1,n):
                    if nums[j] < nums[i] and nums[j] > two:
                        two = nums[j]
                # print(two)
                for k in range(i):
                    if nums[k] < two:
                        return True
        return False
class Solution:
    def find132pattern(self, nums: list[int]) -> bool:
        left = nums[0]
        right = sorted(nums[1:])
        n = len(nums)
        for i in range(1,n-1):
            if nums[i]>left:
                for j in right:
                    if j > left and nums[i] > j:
                        return True
                    elif nums[i] <= j:
                        break
            else:
                left = nums[i]
            right.remove(nums[i])
        return False


class Solution:
    def find132pattern(self, nums: list[int]) -> bool:
        n = len(nums)
        if n < 3:
            return False
        if nums[-1] < nums[-2]:
            twos = [nums[-1]]
            two = twos[0]
        else:
            twos = [nums[-2],nums[-1]]
        for i in range(n-3,-1,-1):
            k = 0
            while twos and nums[i] > twos[-1]:
                two = twos.pop()
                twos.append(nums[i])
                k = 1
            if k and nums[i] < two:
                return True
        return False


class Solution:
    def find132pattern(self, nums: list[int]) -> bool:
        n = len(nums)
        candidate_k = [nums[n-1]]
        max_k = float('-inf')

        for i in range(n-2,-1,-1):
            if nums[i] < max_k:
                return True
            while candidate_k and nums[i] > candidate_k[-1]:
                max_k = candidate_k.pop()
            if nums[i] > max_k:
                candidate_k.append(nums[i])

        return False





t = Solution()
print(t.find132pattern([1,2,3,4]))
print(t.find132pattern([3,1,4,2]))
print(t.find132pattern([-1,3,2,0]))
print(t.find132pattern([-2,1,-2]))
print(t.find132pattern([8,10,4,6,5]))
print(t.find132pattern([26,16,36,16,36,10,80,10,6]))
