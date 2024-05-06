from collections import defaultdict
from itertools import filterfalse
class Solution:
    def findMinHeightTrees(self, n: int, edges: list[list[int]]) -> list[int]:
        if n == 1:
            return [0]
        if n == 2:
            return edges
        data = defaultdict(list)
        for i in edges:
            data[i[0]].append(i[1])
            data[i[1]].append(i[0])
        ends = []
        def dfs(root,level,origin):
            k = 1
            for j in filterfalse(lambda x:x==origin,data[root]):
                k = 0
                dfs(j,level+1,root)
            if k:
                ends.append([root,level])
        dfs(edges[0][0],0,None)
        start = sorted(ends,key=lambda x:x[1]).pop()[0]
        dist = []
        def dfs2(root,level,origin):
            k = 1
            for j in filterfalse(lambda x:x==origin,data[root]):
                k = 0
                dfs2(j,level+1,root)
            if k:
                dist.append([root,level])
        dfs2(start,0,None)
        end,length = sorted(dist,key=lambda x:x[1]).pop()
        candidate = [length // 2] if length % 2 == 0 else [length // 2,length // 2 + 1]
        ans = []
        def dfs3(root,level,origin):
            k = 1
            for j in filterfalse(lambda x:x==origin,data[root]):
                k = 0
                a = dfs3(j,level+1,root)
                if a:
                    if level in candidate:
                        ans.append(root)
                    return True
            if k and root == end:
                return True
            return False
        dfs3(start,0,None)
        return ans





t = Solution()
print(t.findMinHeightTrees(4,[[1,0],[1,2],[1,3]]))
print(t.findMinHeightTrees(10,[[6,3],[4,3],[5,3],[2,3],[10,2],[1,2],[7,2],[8,7],[7,9]]))
print(t.findMinHeightTrees(6,[[3,0],[3,1],[3,2],[3,4],[5,4]]))

