class Solution(object):
    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        rows = len(board)
        cols = len(board[0])
        whitelist = []
        def bfs(current):
            if current in whitelist:
                return
            whitelist.append(current)
            if not current[0] == 0:
                if board[current[0]-1][current[1]] == "O":
                    bfs([current[0]-1,current[1]])

            if not current[0] == rows-1:
                if board[current[0]+1][current[1]] == "O":
                    bfs([current[0]+1,current[1]])
            if not current[1] == 0:
                if board[current[0]][current[1]-1] == "O":
                    bfs([current[0],current[1]-1])

            if not current[1] == cols-1:
                if board[current[0]][current[1]+1] == "O":
                    bfs([current[0],current[1]+1])
        start = []
        for j in range(cols):
            if board[0][j] == "O":
                start.append([0,j])
            if board[rows-1][j] == "O":
                start.append([rows-1,j])
        for t in range(1,rows-1):
            if board[t][0] == "O":
                start.append([t,0])
            if board[t][cols-1] == "O":
                start.append([t,cols-1])
        for k in start:
            bfs(k)
        for i in range(rows):
            for j in range(cols):
                if board[i][j] == "O" and not [i,j] in whitelist:
                    board[i][j] = "X"
        return board

t = Solution()
print(t.solve([["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]))
print(t.solve([["O","X","X","X"],["X","O","O","O"],["X","X","O","X"],["X","O","X","X"]]))
