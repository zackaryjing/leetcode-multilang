class Solution:
    def totalHammingDistance(self, nums: list[int]) -> int:
        n = len(nums)
        # print(list(map(lambda x:list(map(int,list("{:030d}".format(int(bin(x)[3:]))))),nums)))
        a = zip(*map(lambda x:map(int,list("{:030d}".format(int(bin(x)[2:])))),nums))
        # print(list(a))
        # print(a)
        # print(list(map(lambda x:sum(x)*(n-sum(x)),a)))
        res = sum(map(lambda x:sum(x)*(n-sum(x)),a))
        return res

t = Solution()
print(t.totalHammingDistance([4,14,4]))
print(t.totalHammingDistance([4,14,2]))
