'''
My Solution will TLE,,,
Still need improving
'''
from typing import *
from copy import deepcopy
from collections import deque

class Solution2:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        n = len(mat)
        m = len(mat[0])
        for i in range(n):
            for j in range(m):
                if mat[i][j] == 1:
                    mat[i][j] = "1"
        haveone = True
        times = 0
        go = True
        while go:
            go = False
            for i in range(n):
                for j in range(m):
                    if mat[i][j] == times:
                        go = True
                        if i + 1 < n:
                            if mat[i+1][j] == '1':
                                mat[i+1][j] = times + 1
                        if j + 1 < m:
                            if mat[i][j+1] == '1':
                                mat[i][j+1] = times + 1
                        if 0 < i - 1:
                            if mat[i-1][j] == '1':
                                mat[i-1][j] = times + 1
                        if 0 < j - 1:
                            if mat[i][j-1] == '1':
                                mat[i][j-1] = times + 1
            times += 1
        return mat

class Solution3:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        n = len(mat)
        m = len(mat[0])
        assist = [[0 if h[i] == 0 else -1 for i in range(m)] for h in mat]
        print(assist)
        go = True
        times = 0
        while go:
            go = False
            for i in range(n):
                for j in range(m):
                    print(i,j)
                    if assist[i][j] == 0:
                        if i + 1 < n:
                            if mat[i + 1][j] == 1:
                                go = True
                                mat[i + 1][j] = times + 1
                                assist[i + 1][j] = 0
                        if j + 1 < m:
                            if mat[i][j + 1] == 1:
                                go = True
                                mat[i][j + 1] = times + 1
                                assist[i][j + 1] = 0
                        if 0 < i - 1:
                            if mat[i - 1][j] == 1:
                                go = True
                                mat[i - 1][j] = times + 1
                                assist[i - 1][j] = 0
                        if 0 < j - 1:
                            if mat[i][j - 1] == 1:
                                go = True
                                mat[i][j - 1] = times + 1
                                assist[i][j - 1] = 0
            for line in assist:
                print(line)
            print()
            for line in mat:
                print(line)
            print()
            times += 1
        return mat

class Solution3:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        n = len(mat)
        m = len(mat[0])
        for i in range(n):
            for j in range(m):
                if mat[i][j] == 1:
                    mat[i][j] -= 2
        go = True
        times = 0
        matcopy = deepcopy(mat)
        while go:
            go = False
            for i in range(n):
                for j in range(m):
                    # if times == 0:
                        # print(i,j)
                    if mat[i][j] == times:
                        go = True
                        if i + 1 < n:
                            if mat[i + 1][j] == -1:
                                matcopy[i + 1][j] = times + 1
                        if j + 1 < m:
                            if mat[i][j + 1] == -1:
                                matcopy[i][j + 1] = times + 1
                        if 0 <= i - 1:
                            if mat[i - 1][j] == -1:
                                matcopy[i - 1][j] = times + 1
                        if 0 <= j - 1:
                            if mat[i][j - 1] == -1:
                                matcopy[i][j - 1] = times + 1
            # for line in matcopy:
            #     print(line)
            # print()
            # for line in mat:
            #     print(line)
            # print()
            # print("=-"*10)
            mat = deepcopy(matcopy)
            times += 1
        return mat
class Solution:
    def updateMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
        m,n = len(matrix),len(matrix[0])
        dist = [[0] * n for _ in range(m)]
        zeros_pos = [(i,j) for i in range(m) for j in range(n) if matrix[i][j] == 0]
        q = deque(zeros_pos)
        seen = set(zeros_pos)

        while q:
            i,j = q.popleft()
            for ni,nj in [(i-1,j),(i+1,j),(i,j-1),(i,j+1)]:
                if 0 <= ni < m and 0 <= nj < n and (ni ,nj) not in seen:
                    dist[ni][nj] = dist[i][j] + 1
                    q.append((ni,nj))
                    seen.add((ni,nj))
        return dist



t = Solution()
# ans = t.updateMatrix([[0,0,0],[0,1,0],[1,1,1]])
# for k in ans:
#     print(k)

for k in [[0,1,0,1,1],[1,1,0,0,1],[0,0,0,1,0],[1,0,1,1,1],[1,0,0,0,1]]:
    print(k)
print("=-"*10)
ans = t.updateMatrix([[0,1,0,1,1],[1,1,0,0,1],[0,0,0,1,0],[1,0,1,1,1],[1,0,0,0,1]])
for k in ans:
    print(k)
# check = [[0,1,0,1,1],[1,1,0,0,1],[0,0,0,1,0],[1,0,1,1,1],[1,0,0,0,1]]
# for k in check:
#     print(k)
# print()
# check = [[0,1,0,1,2],[1,1,0,0,1],[0,0,0,1,0],[1,0,1,1,1],[2,0,0,0,1]]
# for k in check:
#     print(k)
# print()


