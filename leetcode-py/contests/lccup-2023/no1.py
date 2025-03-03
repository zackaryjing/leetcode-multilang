from sortedcontainers import SortedList
class Solution2:
    def supplyWagon(self, supplies: list[int]) -> list[int]:
        supplies = SortedList(supplies)
        print(supplies)
        n = b = len(supplies)
        print(supplies[3])
        while n > b//2:
            # print(n,b//2)
            print(supplies)
            f = supplies.pop(0)
            m = supplies.pop(0)
            supplies.add(f+m)
            n -= 1
        return list(supplies)
import math
class Solution:
    def supplyWagon(self, supplies: list[int]) -> list[int]:
        n = len(supplies)
        for i in range(math.ceil(n/2)):
            pos = 0
            minum = float('inf')
            for j in range(0,n-1):
                if (a :=supplies[j] + supplies[j+1]) < minum:
                    minum = a
                    pos = j
            n -= 1
            del supplies[pos]
            del supplies[pos]
            supplies.insert(pos,minum)
        return supplies

t = Solution()
print(t.supplyWagon([6,2,2,6,9,8,5,7]))
# print(t.supplyWagon([7,3,6,1,8]))
