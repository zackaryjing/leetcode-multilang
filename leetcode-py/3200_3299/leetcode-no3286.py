# problem: https://leetcode.cn/problems/find-a-safe-walk-through-a-grid/
from typing import *
from copy import deepcopy
from pprint import pprint
from collections import deque


class Solution:
    def findSafeWalk(self, grid: List[List[int]], health: int) -> bool:
        n = len(grid)
        m = len(grid[0])

        costs = [[-1] * m for _ in range(n)]
        borders: Deque[Tuple[int]] = deque()
        borders.append((0, 0))
        costs[0][0] = 1 if grid[0][0] == 1 else 0

        def add_all_zeros(xi, xj, cost):
            zero_list = deque()
            zero_list.append([xi, xj])
            while len(zero_list) > 0:
                i, j = zero_list.popleft()
                # borders.append((i, j))
                for di, dj in [[1, 0], [0, 1], [-1, 0], [0, -1]]:
                    ni, nj = i + di, j + dj
                    if 0 <= ni < n and 0 <= nj < m:
                        if costs[ni][nj] < 0:
                            if grid[ni][nj] == 0:
                                costs[ni][nj] = cost
                                zero_list.append((ni, nj))
                            else:
                                costs[ni][nj] = cost + 1
                                borders.append((ni, nj))

        while len(borders) > 0:
            i, j = borders.popleft()
            cost = costs[i][j]
            # print(i, j)
            for di, dj in [[1, 0], [0, 1], [-1, 0], [0, -1]]:
                ni, nj = i + di, j + dj
                if 0 <= ni < n and 0 <= nj < m:
                    if costs[ni][nj] < 0:
                        if grid[ni][nj] == 1:
                            costs[ni][nj] = cost + 1
                            borders.append((ni, nj))
                        else:
                            costs[ni][nj] = cost
                            add_all_zeros(ni, nj, cost)
        # pprint(costs)
        return costs[n - 1][m - 1] < health


def main():
    test = Solution()
    print(test.findSafeWalk([[0, 1, 0, 0, 0], [0, 1, 0, 1, 0], [0, 0, 0, 1, 0]], 1))
    print(test.findSafeWalk([[0, 1, 1, 0, 0, 0], [1, 0, 1, 0, 0, 0], [0, 1, 1, 1, 0, 1], [0, 0, 1, 0, 1, 0]], 3))
    print(test.findSafeWalk([[1, 1, 1], [1, 0, 1], [1, 1, 1]], 5))


if __name__ == "__main__":
    main()

#
# Created by: zhiya At: 6/14/2025 11:23 PM
#
