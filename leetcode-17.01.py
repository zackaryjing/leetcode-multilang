MASK1 = 2**32
MASK2 = 2**31
MASK3 = 2**31-1
class Solution:
    def add(self, a: int, b: int) -> int:
        a %= MASK1
        b %= MASK1
        while b != 0:
            a,b = (a ^ b) % MASK1,((a & b) << 1)%MASK1
        if a & MASK2:
            return ~((a ^ MASK2) ^ MASK3)
        return a


# MASK1 = 4294967296  # 2^32
# MASK2 = 2147483648  # 2^31
# MASK3 = 2147483647  # 2^31-1
#
# class Solution:
#     def add(self, a: int, b: int) -> int:
#         a %= MASK1
#         b %= MASK1
#         while b != 0:
#             b,a = ((a & b) << 1) % MASK1,(a ^ b) % MASK1
#         if a & MASK2:  # 负数
#             return ~((a ^ MASK2) ^ MASK3)
#         else:  # 正数
#             return a
t = Solution()
print(t.add(-8,10))
print(t.add(1,2))
