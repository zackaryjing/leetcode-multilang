class Solution:
    def canPartition(self, nums: list[int]) -> bool:
        s1 = sum(nums)
        if s1 % 2:
            return False
        else:
            s1 //= 2
        nums.sort(reverse=True)
        n = len(nums)
        def dfs(total,i):
            # print(1,"*"*i,total)
            if total == 0:
                return True
            a = False
            # print(2)
            while i < n:
                # print(3,i)
                if total >= nums[i]:
                    a = dfs(total-nums[i],i+1)
                i += 1
                if a:
                    break
            if a:
                return True
            return False
        return dfs(s1,0)

t = Solution()
print(t.canPartition([14,9,8,4,3,2]))
# print(t.canPartition([1,2,3,5]))
# print(t.canPartition([1,5,11,5]))
# print(t.canPartition([4,7,1,6,2,3,9,8,5,10]))
# print(t.canPartition([4,7,1,11,6,2,3,9,8,5,10]))
