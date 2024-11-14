from collections import defaultdict
class Solution:
    def checkDistances(self, s: str, distance: list[int]) -> bool:
        times = defaultdict(int)
        for i in range(len(s)):
            times[s[i]] = (i - times[s[i]])

        for k,v in times.items():
            if distance[ord(k)-ord('a')] != v-1:
                return False
        return True

t = Solution()
print(t.checkDistances("abaccb",[1,3,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]))