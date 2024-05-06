from itertools import starmap,pairwise,filterfalse
class Solution:
    def findPoisonedDuration(self, timeSeries: list[int], duration: int) -> int:
        processed = list(starmap(lambda x,y:y-x,pairwise(timeSeries)))
        ans = 0
        for i in processed:
            if i <= duration:
                ans += i
            else:
                ans += duration
        return ans + duration

t = Solution()
print(t.findPoisonedDuration([1,2,6,10],3))
