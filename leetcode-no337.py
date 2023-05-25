from typing import *
# Definition for a binary tree node.
import binarytree
from collections import defaultdict
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution2:
    def rob(self, root: Optional[TreeNode]) -> int:
        f = defaultdict(int)
        g = defaultdict(int)
        def dfs(root,pos):
            haveson = 0
            if root.left:
                haveson = 1
                dfs(root.left,pos*2)
            if root.right:
                haveson = 1
                dfs(root.right,pos*2+1)
            if not haveson:
                f[pos] = root.val
            else:
                f[pos] = g[pos*2] + g[pos*2+1] + root.val
                g[pos] = max(f[pos*2],g[pos*2]) + max(f[pos*2+1],g[pos*2+1])
        dfs(root,1)
        # print(f)
        # print(g)
        return max(f[1],g[1])

class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        # f = defaultdict(int)
        # g = defaultdict(int)
        def dfs(root,pos):
            haveson = 0
            data1 = [0,0]
            data2 = [0,0]
            if root.left:
                haveson = 1
                data1 = dfs(root.left,pos*2)
            if root.right:
                haveson = 1
                data2 = dfs(root.right,pos*2+1)
            data = [0,0]
            if not haveson:
                data[0] = root.val
                # f[pos] = root.val
            else:
                data[0] = data1[1] + data2[1] + root.val
                # f[pos] = g[pos*2] + g[pos*2+1] + root.val
                data[1] = max(data1[0],data1[1]) + max(data2[0],data2[1])
                # g[pos] = max(f[pos*2],g[pos*2]) + max(f[pos*2+1],g[pos*2+1])
            return data
        ans = dfs(root,1)
        return max(ans)

test1 = binarytree.build([3,2,3,None,3,None,1])
test2 = binarytree.build([3,4,5,1,3,None,1])
t = Solution()
print(t.rob(test1))
print(t.rob(test2))
