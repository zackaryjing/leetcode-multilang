from typing import *
import math

import sortedcontainers


class Solution2:
    def powerfulIntegers(self, x: int, y: int, bound: int) -> List[int]:
        ans = []
        a = math.log(min(x, y))
        if a == 0:
            times = 20
        else:
            times = int(math.log(bound) / a) + 1
        for i in range(2,bound+1):
            for k in range(times):
                jump = False
                for j in range(times):
                    if x ** k + y ** j == i:
                        ans.append(i)
                        jump = True
                        break
                if jump:
                    break
        return ans



class Solution:
    def powerfulIntegers(self, x: int, y: int, bound: int) -> List[int]:
        if bound == 0:
            return []
        a = math.log(min(x, y))
        if a == 0:
            times = 20
        else:
            times = int(math.log(bound) / a) + 1
        ans = sortedcontainers.SortedSet()
        for i in range(times):
            for k in range(times):
                if (tmp := (x**i + y**k)) <= bound:
                    ans.add(tmp)
        return list(ans)






t = Solution()
print(t.powerfulIntegers(2,3,10))
print(t.powerfulIntegers(2,1,10))


