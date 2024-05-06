class Solution:
    def updateMatrix(self, mat: list[list[int]]) -> list[list[int]]:
        rows = len(mat)
        cols = len(mat[0])
        mid = [[None for i in range(cols)] for j in range(rows)]
        current = 1
        while None in sum(mid,[]):
            for i in range(rows):
                for j in range(cols):
                    if mat[i][j] == None and \
                            (mat[i][j+1] == current - 1 or \
                            mat[i][j-1] == current - 1 or \
                            mat[i+1][j] == current - 1 or \
                            mat[i-1][j] == current - 1 ):
                        mid[i][j] = current
            current += 1
        return mid

class Solution:
    def updateMatrix(self, mat: list[list[int]]) -> list[list[int]]:
        cols = len(mat[0])
        rows = len(mat)
        res = [[0 if mat[i][j] == 0 else float('inf') for i in range(cols)] for j in range(rows)]
        def dfs(cr,cc):
            print(res[2][1])
            if cr == rows-1 and cc == cols-1:
                res[cr][cc] = min([res[cr][cc - 1], res[cr - 1][cc]]) + 1
            elif cr == rows-1:
                res[cr][cc] = min([res[cr][cc - 1], res[cr - 1][cc], dfs(cr, cc + 1)]) + 1
            elif cc == cols-1:
                res[cr][cc] = min([res[cr][cc - 1], res[cr - 1][cc], dfs(cr + 1, cc)]) + 1
            elif cc == 0 and cr == 0:
                res[cr][cc] = min([dfs(cr + 1, cc), dfs(cr, cc + 1)]) + 1
            elif cc == 0:
                res[cr][cc] = min([res[cr - 1][cc], dfs(cr + 1, cc), dfs(cr, cc + 1)]) + 1
            elif cr == 0:
                res[cr][cc] = min([res[cr][cc - 1], dfs(cr + 1, cc), dfs(cr, cc + 1)])+1
            else:
                res[cr][cc] = min([res[cr][cc - 1], res[cr - 1][cc], dfs(cr + 1, cc), dfs(cr, cc + 1)]) + 1
            if mat[cc][cr] == 0:
                res[cc][cr] = 0
            print(res[1][2],"*******")
            return res[cc][cr]
        dfs(0,0)
        return res

t = Solution()
print(t.updateMatrix([[0,0,0],[0,1,0],[0,0,0]]))
print(t.updateMatrix([[0,0,0],[0,1,0],[1,1,1]]))
