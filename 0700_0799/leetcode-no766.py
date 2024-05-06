from collections import defaultdict
class Solution(object):
    def isToeplitzMatrix(self, matrix):
        data = defaultdict(int)
        rows = len(matrix)
        cols = len(matrix[0])
        for j in range(cols):
            data[j] = matrix[0][j]
        for i in range(rows):
            data[-i] = matrix[i][0]
        print([[i,j] for i,j in data.items()])
        for i in range(rows):
            for j in range(cols):
                if not matrix[i][j] == data[j-i]:
                    return False
        return True

t = Solution()
print(t.isToeplitzMatrix([[1,3,3,4],[5,1,2,3],[9,5,1,2]]))




