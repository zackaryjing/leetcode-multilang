from functools import cmp_to_key
class Solution:
    def largestNumber(self, nums: list[int]) -> str:
        nums = list(map(str,nums))
        nums.sort(key=cmp_to_key(lambda x,y:int(x+y)-int(y+x)))
        return "0" if nums[0] == "0" else ''.join(reversed(nums))


class Solution2:
    def largestNumber(self, nums: list[int]) -> str:
        def compare(x, y): return int(y+x) - int(x+y)
        nums = sorted(map(str, nums), key=cmp_to_key(compare))
        return "0" if nums[0]=="0" else "".join(nums)



t = Solution()
print(t.largestNumber([10,2]))
print(t.largestNumber([0,0]))
print(t.largestNumber([3,30,34,5,9]))
print(t.largestNumber([34323,3432]))
