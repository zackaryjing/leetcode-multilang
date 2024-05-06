from collections import  Counter
class Solution:
    def combinationSum2(self, candidates: list[int], target: int) -> list[list[int]]:
        def dfs(pos:int,rest:int):
            nonlocal sequence
            if rest == 0:
                ans.append(sequence[:])
                return
            if pos == len(freq) or rest < freq[pos][0]:
                return
            dfs(pos + 1, rest)

            most = min(rest//freq[pos][0],freq[pos][1])
            for i in range(1,most+1):
                sequence.append(freq[pos][0])
                dfs(pos + 1,rest - i * freq[pos][0])
            sequence = sequence[:-most]

        freq = sorted(Counter(candidates).items())
        ans = list()
        sequence = list()
        dfs(0,target)
        return ans

t = Solution()
print(t.combinationSum2())




