class Solution:
    def partition(self, s: str) -> list[list[str]]:
        n = len(s)
        table = [[True] * n for _ in range(n)]

        for i in range(n-1,-1,-1):
            for j in range(i+1,n):
                table[i][j] = (s[i] == s[j]) and table[i+1][j-1]
        print(table)
        mid = []
        ans = []
        def dfs(i:int):
            for j in range(i,n):
                if table[i][j]:
                    mid.append(s[i:j+1])
                    dfs(j+1)
                    mid.pop()
            if i == n:
                ans.append(mid[:])
                return
        dfs(0)
        return ans

t = Solution()
print(t.partition("aab"))
