class Solution(object):
    def maximalSquare(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        matrix = [list(map(int,i)) for i in matrix]
        # print(matrix)
        square = 0
        if 1 in sum(matrix,[]):
            square = 1
        rows = len(matrix)
        cols = len(matrix[0])
        for i in range(rows):
            for j in range(cols):
                # print(i,j)
                current = 0

                while i+current <rows and j+current < cols and \
                all(matrix[i+current][j:j+current]+[matrix[t][j+current] for t in range(i,i+current)]):
                    current += 1
                    # print(current)
                if (current-1)**2 > square:
                    square = (current-1)**2
        return square


t = Solution()
print(t.maximalSquare([["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]))
print(t.maximalSquare([["1","1"],["1","1"]]))
print(t.maximalSquare([['1']]))
