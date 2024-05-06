class Solution:
    def totalNQueens(self, n: int) -> int:
        path = []
        ans = 0
        def dfs(lvl,pos):
            nonlocal ans
            for k in range(lvl):
                if pos == path[k] or pos + lvl == k + path[k] or lvl - pos == k - path[k]:
                    return
            path.append(pos)
            if lvl + 1 == n:
                ans += 1
            for j in range(n):
                dfs(lvl+1,j)
            path.pop()
        for j in range(n):
            dfs(0,j)
        return ans

t = Solution()
print(t.totalNQueens(8))