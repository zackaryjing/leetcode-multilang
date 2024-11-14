from typing import *
from collections import defaultdict
class Solution2:
    def singleNumber(self, nums: List[int]) -> int:
        digits = defaultdict(int)
        for k in nums:
            # print(bin(k))
            for j in range(32):
                if (k >> j) & 1:
                    if j != 31:
                        digits[j] = (digits[j] + 1) % 3

        ans = ["0"]*32
        # print(digits.items())
        for i,j in digits.items():
            ans[31-i] = str(j)
        return int("".join(ans),2)

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ans = 0
        for i in range(32):
            total = sum((num >> i) & 1 for num in nums)
            if total % 3:
                if i == 31:
                    ans -= (1 << 31)
                else:
                    ans |= (1 << i)
        return ans











t = Solution()
print(t.singleNumber([0,1,0,1,0,1,99]))
print(t.singleNumber([2,2,3,2]))

