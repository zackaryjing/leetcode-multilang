class Solution:
    def exist(self, board: list[list[str]], word: str) -> bool:
        rows = len(board)
        cols = len(board[0])
        candidate = []
        for i in range(rows):
            for j in range(cols):
                if board[i][j] == word[0]:
                    candidate.append([i,j])
        if not candidate:
            return False
        valid = []
        def dfs(row,col,current,path):
            if current == len(word) - 1:
                valid.append(1)
                return
            if not row == 0:
                if board[row-1][col] == word[current + 1] and not [row-1,col] in path:
                    dfs(row-1,col,current + 1,path+[[row-1,col]])
            if not col == 0:
                if board[row][col-1] == word[current + 1] and not [row,col-1] in path:
                    dfs(row,col-1,current + 1,path+[[row,col-1]])
            if not row == rows-1:
                if board[row+1][col] == word[current + 1] and not [row+1,col] in path:
                    dfs(row+1,col,current + 1,path+[[row+1,col]])
            if not col == cols-1:
                if board[row][col+1] == word[current + 1] and not [row,col+1] in path:
                    dfs(row,col+1,current + 1,path+[[row,col+1]])

        for i,j in candidate:
            dfs(i,j,0,[[i,j]])
        if valid:
            return True
        return False

t = Solution()
print(t.exist([["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]],"ABCCED"))
print(t.exist([["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]],"SEE"))
print(t.exist([["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]],"ABC"))
print(t.exist([["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]],"ABCDE"))
print(t.exist([["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]],"ABCB"))
