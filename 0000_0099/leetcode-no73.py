class Solution(object):
    def setZeroes(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        rows = set()
        lines = set()
        r,l = len(matrix),len(matrix[0])
        for i in range(r):
            for j in range(l):
                if matrix[i][j] == 0:
                    rows.add(i)
                    lines.add(j)
        for j in range(r):
            if j in rows:
                matrix[j] = [0]*l
            for t in lines:
                matrix[j][t] = 0
        return matrix

t = Solution()
print(t.setZeroes([[0,1,2,0],[3,4,5,2],[1,3,1,5]]))