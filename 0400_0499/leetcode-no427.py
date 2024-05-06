# Definition for a QuadTree node.
import queue
class Node:
    def __init__(self, val, isLeaf, topLeft=None, topRight=None, bottomLeft=None, bottomRight=None):
        self.val = val
        self.isLeaf = isLeaf
        self.topLeft = topLeft
        self.topRight = topRight
        self.bottomLeft = bottomLeft
        self.bottomRight = bottomRight

class Solution2:
    def construct(self, grid: list[list[int]]) -> Node:
        n = len(grid)
        root = Node()
        while n >= 1:
            if not (0 and 1 in sum([x[:n//2] for x in grid[:n//2]],[])):
                root.isLeaf = True
                root.val = grid[0,0]
            if not (0 and 1 in sum([x[n//2:] for x in grid[:n//2]],[])):
                root.isLeaf = True
                root.val = grid[0,0]
            if not (0 and 1 in sum([x[:n//2] for x in grid[n//2:]],[])):
                root.isLeaf = True
                root.val = grid[0,0]
            if not (0 and 1 in sum([x[n//2:] for x in grid[n//2:]],[])):
                root.isLeaf = True
                root.val = grid[0,0]


class Solution2:
    def construct(self, grid: list[list[int]]) -> Node:
        n = len(grid)
        a = queue.Queue
        a.put([0,n])
        res = []
        while not a.empty():
            lt,rb = a.get()
            if len(set(sum([x[lt[1]:rb[1]] \
                    for x in grid[lt[0]:rb[0]]],[]))) == 1:
                res.append([1,grid[lt[0],lt[1]]])
            else:
                res.append([0,1])
                a.put([lt[:],])

class Solution:
    def construct(self, grid: list[list[int]]) -> Node:
        def dfs(r0:int,c0:int,r1:int,c1:int):
            if all(grid[i][j] == grid[r0][c0] for i in  range(r0,r1) for j in range(c0,c1)):
                return Node(grid[r0][c0] == 1,True)
            return Node(
                True,
                False,
                dfs(r0,c0,(r0+r1) // 2 ,(c0+c1) // 2),
                dfs(r0, (c0+c1)//2, (r0 + r1) // 2,c1),
                dfs((r0+r1)//2, c0, r1, (c0 + c1) // 2),
                dfs((r0 + r1) //2 , (c0+c1)//2, r1,c1),
            )
        return dfs(0,0,len(grid),len(grid))

t = Solution()
print(t.construct([[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,1,1,1,1],[1,1,1,1,1,1,1,1],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0],[1,1,1,1,0,0,0,0]]))



