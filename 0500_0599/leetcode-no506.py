from collections import defaultdict
class Solution:
    def findRelativeRanks(self, score: list[int]) -> list[str]:
        cp = score[:]
        score.sort(reverse=True)
        n = len(score)
        data = defaultdict(str)
        for i in range(n):
            if i == 0:
                data[score[i]] = "Gold Medal"
            elif i == 1:
                data[score[i]] = "Silver Medal"
            elif i == 2:
                data[score[i]] = "Bronze Medal"
            else:
                data[score[i]] = str(i+1)
        ans = []
        for j in cp:
            ans.append(data[j])
        return ans

t = Solution()
print(t.findRelativeRanks([5,4,3,2,1]))


