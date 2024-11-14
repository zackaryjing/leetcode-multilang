from collections import defaultdict
class Solution3:
    def findDiagonalOrder(self, mat: list[list[int]]) -> list[int]:
        rows,cols = len(mat),len(mat[0])
        res = [[] for i in range(cols+rows-1)]
        for i in range(rows):
            for j in range(cols):
                res[i+j].append(mat[i][j])
        for k in range(rows+cols):
            if k % 2 == 0:
                res[k].reverse()
        return sum(res,[])

class Solution:
    def findDiagonalOrder(self, mat: list[list[int]]) -> list[int]:
        rows,cols = len(mat),len(mat[0])
        res = []
        data = defaultdict(list)
        for i in range(rows):
            for j in range(cols):
                data[j+i].append(mat[i][j])
        for k in range(rows+cols-1):
            res.extend(data[k])
        return res


class Solution2:
    def findDiagonalOrder(self, mat: list[list[int]]) -> list[int]:
        res = []
        rows,cols = len(mat),len(mat[0])
        pass


t = Solution()
print(t.findDiagonalOrder([[1,2,3],[4,5,6],[7,8,9]]))
print(t.findDiagonalOrder([[1,2],[3,4]]))
