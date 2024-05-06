class Solution:
    def minElements(self, nums: list[int], limit: int, goal: int) -> int:
        difference = abs(goal - sum(nums))
        return difference // limit if difference % limit == 0 else difference // limit + 1
t = Solution()
print(t.minElements([1,-1,1],3,-4))
print(t.minElements([1,-10,9,1],100,0))
print(t.minElements([-1,0,1,1,1],1,771843707))
