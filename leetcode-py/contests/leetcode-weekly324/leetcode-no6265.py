from collections import defaultdict
class Solution:
    def similarPairs(self, words: list[str]) -> int:
        data = defaultdict(int)
        res = 0
        for word in words:
            norepeat = set()
            for letter in word:
                norepeat.add(letter)
            data[''.join(sorted(list(norepeat)))] += 1
        for j in data.values():
            res += j*(j-1)//2
        return res

t = Solution()
print(t.similarPairs(["aba","aabb","abcd","bac","aabc"]))
print(t.similarPairs(["aabb","ab","ba"]))
print(t.similarPairs(["nba","cba","dba"]))

