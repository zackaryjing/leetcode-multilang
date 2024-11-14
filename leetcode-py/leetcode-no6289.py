from itertools import product,filterfalse
from functools import reduce
class Solution:
    def xorBeauty(self, nums: list[int]) -> int:
        n = len(nums)
        a = product(range(n),repeat=3)
        b = list(map(lambda x:(nums[x[0]] | nums[x[1]]) & nums[x[2]],a))
        d = list(filterfalse(lambda x:~(b.count(x))%2,set(b)))
        # print(list(d))
        # for i in set(b):
        #     if b.count(i) % 2 != 0:
        #         d.append(i)
        # if not d:
        #     return 0
        # d = [1,4]
        if not d:
            return 0
        return reduce(lambda x,y:x^y,d)


t = Solution()
print(t.xorBeauty([1,4]))
print(t.xorBeauty([4,4]))
print(t.xorBeauty([5,4]))
print(t.xorBeauty([15,45,20,2,34,35,5,44,32,30]))
