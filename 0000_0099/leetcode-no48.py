class Solution(object):
    def rotate(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: None Do not return anything, modify matrix in-place instead.
        """
        length = len(matrix)-1
        half1 =  length//2+1
        half2 = (length+1)// 2
        for i in range(half2):
            for j in range(half1):
                matrix[j][length-i],matrix[length-i][length-j],matrix[length-j][i],matrix[i][j]=matrix[i][j],matrix[j][length-i],matrix[length-i][length-j],matrix[length-j][i]
        return matrix

t = Solution()
print(t.rotate([[1,2,3],[4,5,6],[7,8,9]]))
print(t.rotate([[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]))
print(t.rotate([[]]))
