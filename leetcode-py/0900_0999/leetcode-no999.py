from typing import *


class Solution:
    def numRookCaptures(self, board: List[List[str]]) -> int:
        directions: List[List[int]] = [[-1, 0], [1, 0], [0, -1], [0, 1]]
        ans = 0
        found = False
        for r, line in enumerate(board):
            for c, ch in enumerate(line):
                if ch == 'R':
                    for dy, dx in directions:
                        nr, nc = r + dy, c + dx
                        while 0 <= nr < 8 and 0 <= nc < 8:
                            if board[nr][nc] == 'p':
                                ans += 1
                                break
                            elif board[nr][nc] != '.':
                                break
                            nr, nc = nr + dy, nc + dx
                    found = True
                    break
            if found:
                break
        return ans


def main():
    a = 0
    b = 0
    test = Solution()
    print(test.numRookCaptures([[".", ".", ".", ".", ".", ".", ".", "."], [".", "p", "p", "p", "p", "p", ".", "."],
                                [".", "p", "p", "B", "p", "p", ".", "."], [".", "p", "B", "R", "B", "p", ".", "."],
                                [".", "p", "p", "B", "p", "p", ".", "."], [".", "p", "p", "p", "p", "p", ".", "."],
                                [".", ".", ".", ".", ".", ".", ".", "."], [".", ".", ".", ".", ".", ".", ".", "."]]))
    print(test.numRookCaptures([[".", ".", ".", ".", ".", ".", ".", "."], [".", ".", ".", "p", ".", ".", ".", "."],
                                [".", ".", ".", "R", ".", ".", ".", "p"], [".", ".", ".", ".", ".", ".", ".", "."],
                                [".", ".", ".", ".", ".", ".", ".", "."], [".", ".", ".", "p", ".", ".", ".", "."],
                                [".", ".", ".", ".", ".", ".", ".", "."], [".", ".", ".", ".", ".", ".", ".", "."]]))


if __name__ == "__main__":
    main()
