from typing import *
# Definition for a binary tree node.
import binarytree
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution2:
    def addOneRow(self, root: Optional[TreeNode], val: int, depth: int) -> Optional[TreeNode]:
        if depth == 1:
            tmp = binarytree.Node(val,left=root)
            return tmp
        def bfs(root,lvl):
            if lvl == depth - 1:
                tmpl = binarytree.Node(val, left=root.left)
                tmpr = binarytree.Node(val, right=root.right)
                root.left = tmpl
                root.right = tmpr
            if root.left:
                bfs(root.left,lvl+1)
            if root.right:
                bfs(root.right,lvl+1)
        bfs(root,1)
        return root
class Solution:
    def addOneRow(self, root: Optional[TreeNode], val: int, depth: int) -> Optional[TreeNode]:
        if depth == 1:
            tmp = TreeNode(val,left=root)
            return tmp
        def bfs(root,lvl):
            if lvl == depth - 1:
                tmpl = TreeNode(val, left=root.left)
                tmpr = TreeNode(val, right=root.right)
                root.left = tmpl
                root.right = tmpr
            if root.left:
                bfs(root.left,lvl+1)
            if root.right:
                bfs(root.right,lvl+1)
        bfs(root,1)
        return root

t = Solution2()
test = binarytree.build([4,2,None,3,1])
test1 = binarytree.build([4,2,6,3,1,5])
print(t.addOneRow(test1,1,1))




