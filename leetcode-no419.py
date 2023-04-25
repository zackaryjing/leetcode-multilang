class Solution:
    def countBattleships(self, board: list[list[str]]) -> int:
        rows = len(board)
        cols = len(board[0])
        nums = 0
        for i in range(rows):
            for j in range(cols):
                if board[i][j] == 'X':
                    k = 0
                    if not i == rows - 1 and board[i+1][j] == 'X':
                        k = 1
                        break
                    if not i == 0 and board[i-1][j] == 'X':
                        k = 1
                        break
                    if not j == cols and board[i][j+1] == 'X':
                        k = 1
                        break
                    if not j == 0 and board[i][j-1] ==  "X":
                        k = 1
                        break
                if not k:
                    nums += 1
        return nums

class Solution:
    def countBattleships(self, board: list[list[str]]) -> int:
        rows = len(board)
        cols = len(board[0])
        nums = 0
        past = []
        for i in range(rows):
            for j in range(cols):
                if board[i][j] == 'X':
                    past.append([i,j])
                    k = 0
                    if not i == 0 and board[i-1][j] == 'X':
                        k = 1
                    if not j == 0 and board[i][j-1] ==  "X":
                        k = 1
                    if not k:
                        nums += 1
        return nums

t = Solution()
print(t.countBattleships([["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]))
print(t.countBattleships([["X","X",".","X"],[".",".",".","X"],["X",".",".","."],["X",".","X","X"]]))
print(t.countBattleships([['.']]))
