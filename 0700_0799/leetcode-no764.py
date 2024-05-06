from typing import *
import numpy as np
from itertools import filterfalse


class Solution:
    def orderOfLargestPlusSign(self, n: int, mines: List[List[int]]) -> int:
        board = np.ones((n, n))
        store = np.ones((n, n))
        for i, j in mines:
            board[i][j] = 0
        line = np.zeros(n)
        for i in range(n):
            line = line * board[i] + board[i]
            store[i] = line
        line = np.zeros(n)
        for i in range(n - 1, -1, -1):
            line = line * board[i] + board[i]
            store[i] = np.minimum(store[i], line)
        line = np.zeros(n)
        for i in range(n):
            line = line * board[:, i] + board[:, i]
            store[:, i] = np.minimum(store[:, i], line)
        line = np.zeros(n)
        for i in range(n - 1, -1, -1):
            line = line * board[:, i] + board[:, i]
            store[:, i] = np.minimum(store[:, i], line)
        return np.max(store)


test = Solution()
print(test.orderOfLargestPlusSign(5, [[4, 2]]))
