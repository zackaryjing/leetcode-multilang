from typing import *
from collections import deque
class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        ans = []
        n = len(graph)
        def dfs(pos,path):
            if pos == n - 1:
                ans.append(path+[pos])
                return
            for nxt in graph[pos]:
                dfs(nxt,path+[pos])
        dfs(0,[])
        return ans

t = Solution()
print(t.allPathsSourceTarget([[1,2],[3],[3],[]]))
