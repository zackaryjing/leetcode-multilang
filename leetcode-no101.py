# Definition for a binary tree node.
from collections import defaultdict
import binarytree
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def isSymmetric(self, root: TreeNode)-> bool:
        a = defaultdict(list)
        def bfs(root,lvl):
            if root:
                a[lvl].append(root.val)
                bfs(root.left,lvl + 1)
                bfs(root.right,lvl + 1)
            else:
                a[lvl].append(None)
        bfs(root,0)
        for i in a.values():
            if i != i[::-1]:
                return False
        return True


a = binarytree.tree(3)
print(a)
t = Solution()
print(t.isSymmetric(a))