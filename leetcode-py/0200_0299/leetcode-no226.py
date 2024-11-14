from typing import *
import binarytree
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def dfs(root):
            if root:
                root.left,root.right = root.right,root.left
            else:
                return
            if root.left:
                dfs(root.left)
            if root.right:
                dfs(root.right)
        dfs(root)
        return root
test = binarytree.tree(3)
print(test)
t = Solution()
print(t.invertTree(test))
print(t.invertTree(None))

