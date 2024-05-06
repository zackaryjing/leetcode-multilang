class Solution:
    def gameOfLife(self, board: list[list[int]]) -> None:
        """
        Do not return anything, modify board in-place instead.
        """
        rows = len(board)
        cols = len(board[0])
        res = [[0]*cols for _ in range(rows)]
        board.insert(0,[0]*cols)
        board.append([0]*cols)
        def check(i,j):
            total = 0
            total += ((board[i-1][j] == 1) + (board[i+1][j] == 1))
            if not j == 0:
                total += ((board[i-1][j-1])+(board[i][j-1])+(board[i+1][j-1]))
            if not j == cols-1:
                total += ((board[i - 1][j + 1]) + (board[i][j + 1]) + (board[i + 1][j + 1]))
            return total
        for i in range(1,rows+1):
            for j in range(cols):
                if board[i][j] == 1:
                    if check(i,j) in [2,3]:
                        res[i-1][j] = 1
                if board[i][j] == 0:
                    if check(i,j) == 3:
                        res[i-1][j] = 1
        del board[:]
        board.extend(res[:])
        return board

t = Solution()
print(t.gameOfLife([[0,1,0],[0,0,1],[1,1,1],[0,0,0]]))
print(t.gameOfLife([[1,1],[1,0]]))
