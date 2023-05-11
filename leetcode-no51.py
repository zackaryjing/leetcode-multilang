from typing import *
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        path = []
        res = []
        def dfs(lvl,pos):
            # print(lvl,pos)
            for k in range(lvl):
                if pos == path[k] or pos + lvl == k + path[k] or lvl - pos == k - path[k]:
                    return
            path.append(pos)
            if lvl + 1 == n:
                # print(path)
                tmp = []
                for t in path:
                    base = ["."] * n
                    base[t] = "Q"
                    tmp.append("".join(base))
                res.append(tmp)
            for j in range(n):
                dfs(lvl+1,j)
            path.pop()
        for j in range(n):
            dfs(0,j)
        return res

t = Solution()
print(t.solveNQueens(4))