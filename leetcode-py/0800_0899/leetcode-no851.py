from collections import defaultdict
class Solution:
    def loudAndRich(self, richer: list[list[int]], quiet: list[int]) -> list[int]:
        n = len(quiet)
        data = defaultdict(list)
        for i in richer:
            data[i[1]].append(i[0])
        vis = [[quiet[i],i,0] for i in range(n)]
        fathers = set([x[1] for x in richer])
        sons = set([x[0] for x in richer])
        starts = fathers-sons
        def dfs(current):
            mid = []
            if data[current]:
                for i in data[current]:
                    if not vis[i][2]:
                        dfs(i)
                    mid.append(vis[i])
                mid.append(vis[current])
                vis[current] = sorted(mid)[0][0:2]+[1]
            else:
                vis[current] = vis[current][0:2]+[1]
        for i in starts:
            dfs(i)
        return [i[1] for i in vis]
t = Solution()
print(t.loudAndRich([[1,0],[2,0],[6,2],[5,2],[4,1],[3,1]],[3,6,4,2,5,1,0]))
'''[[0, 6], [2, 3], [0, 6], [2, 3], [5, 4], [1, 5], [0, 6]]'''
print(t.loudAndRich([[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]],[3,2,5,4,6,1,7,0]))
print(t.loudAndRich([],[0]))
