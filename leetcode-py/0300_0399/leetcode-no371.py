class Solution2:
    '''无法通过负数'''
    def getSum(self, a: int, b: int) -> int:
        while b != 0:
            # print(a,b)
            a, b = a ^ b, (a & b) << 1
        return a
MASK1 = 2**32
MASK2 = 2**31
MASK3 = 2**31 - 1
class Solution:
    def getSum(self, a: int, b: int) -> int:
        a %= MASK1
        b %= MASK1
        while b != 0:
            a, b = a ^ b, (a & b) << 1
        if a & MASK2:
            return ~((a ^ MASK2) ^ MASK3)
        else:
            return a


t = Solution()
a = int("1101",2)
b = int("100",2)
print(t.getSum(a,b))
