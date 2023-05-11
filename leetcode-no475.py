from typing import *
class Solution:
    def findRadius(self, houses: List[int], heaters: List[int]) -> int:
        houses.sort()
        heaters.sort()
        def findnearest(num):
            left = 0
            right = len(heaters) - 1
            while left < right:
                mid = (left + right + 1) // 2
                print(left,mid,right,"+++")
                if heaters[mid] < num:
                    left = mid
                elif heaters[mid] > num:
                    right = mid - 1
                else:
                    print(mid)
                    return mid
            if left == (len(heaters) - 1) or num - heaters[left] <= heaters[left+1] - num:
                print(left,'---')
                return left
            else:
                print(left+1,'-=-')
                return left + 1
        maxum = 0
        for i in houses:
            if (tmp:=abs(i-heaters[findnearest(i)])) > maxum:
                maxum = tmp
        return maxum

t = Solution()
# print(t.findRadius([1,5],[2]))
# print(t.findRadius([1,2,3,4],[1,4]))
# print(t.findRadius([1,2,3],[2]))
# print(t.findRadius([1,5],[10]))
print(t.findRadius([282475249,622650073,984943658,144108930,470211272,101027544,457850878,458777923],\
                [823564440,115438165,784484492,74243042,114807987,137522503,441282327,16531729,823378840,143542612]))
