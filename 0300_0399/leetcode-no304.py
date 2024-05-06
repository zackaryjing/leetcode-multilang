from itertools import accumulate
class NumMatrix:

    def __init__(self, matrix: list[list[int]]):
        for i in range(len(matrix)):
            matrix[i] = list(accumulate(matrix[i]))
        temp = list(zip(*matrix))
        for j in range(len(temp)):
            temp[j] = list(accumulate(temp[j]))
        self.matrix = list(zip(*temp))
        self.matrix.insert(0,[0]*len(self.matrix[0]))
        print(self.matrix)
    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        if col1 == 0:
            num3 = 0
            num1 = 0
        else:
            num1 = self.matrix[row1][col1 - 1]
            num3 = self.matrix[row2+1][col1-1]
        num2 = self.matrix[row1][col2]
        return self.matrix[row2+1][col2] - num2 - num3 + num1


t = NumMatrix([[3,0,1,4,2],[5,6,3,2,1],[1,2,0,1,5],[4,1,0,1,7],[1,0,3,0,5]])
print(t.sumRegion(*[2,1,4,3]))
print(t.sumRegion(*[1,1,2,2]))
print(t.sumRegion(*[1,2,2,4]))
print(t.sumRegion(*[0,0,0,3]))
s = NumMatrix([[1],[-7]])
print(s.sumRegion(*[1,0,1,0]))
# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)