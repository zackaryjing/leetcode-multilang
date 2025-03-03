from typing import *
from itertools import accumulate
from collections import defaultdict
import math


class Solution:
    def maximumOr(self, nums: List[int], k: int) -> int:
        if nums == []:
            return 0
        maxum = max(nums)
        lvl = int(math.log2(maxum))
        base = 1 << lvl
        candidate = [i for i in nums if i >= base]
        # print(candidate,base)
        if len(candidate) == 1:
            ans = 0
            nums.remove(candidate[0])
            for u in nums:
                ans |= u
            ans |= (candidate[0] << k)
            return ans
        elif len(candidate) == 0:
            return 0
        data = defaultdict(int)
        for i in nums:
            for j in range(lvl+1):
                if (i >> j) & 1:
                    if data[j] == 0:
                        data[j] = 1
                    else:
                        data[j] = 2
                        break

        # basicnum = 0
        # for digits,val in data.items():
        #     if val != 0:
        #         basicnum += (1 << digits)
        # print(basicnum,"basicnum")

        maxum = 0
        maxpos = 0
        for h in range(len(candidate)):
            tmp = candidate[h]
            delta = 0
            for p in range(lvl+1):
                if (tmp >> p) & 1:
                    if data[p] == 1:
                        delta -= (1 << p)
                    if data[p+k] == 0:
                        # print(p+k)
                        delta += (1 << (p + k))
            if delta > maxum:
                # print(h,candidate[h],delta)
                maxpos = h
                maxum = delta
        # print(candidate,maxpos,"best fit")
        nums.remove(candidate[maxpos])
        ans = 0
        for u in nums:
            ans |= u
        # print(ans)
        # print(ans,"ans is")
        ans |= candidate[maxpos] << k
        # print(candidate[maxpos],k)
        # print(ans,"ans is")
        # print(data)

        return ans

t = Solution()
print(t.maximumOr([98,54,6,34,66,63,52,39,62,46,75,28,65,18,37,18,97,13,80,33,69,91,78,19,40],2))
print(t.maximumOr([23,25], 2))
print(t.maximumOr([], 1))
print(t.maximumOr([3,3,7], 0))
print(t.maximumOr([7,7,7], 1))
print(t.maximumOr([], 1))
print(t.maximumOr([12, 9], 1))
print(t.maximumOr([8,1,2],2))
