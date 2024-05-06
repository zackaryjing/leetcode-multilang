# Definition for a binary tree node.
import binarytree
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def convertBST(self, root:TreeNode) -> TreeNode:
        def dfs(root:TreeNode):
            nonlocal total
            if root:
                dfs(root.right)
                total += root.val
                root.val = total
                dfs(root.left)
        total = 0
        dfs(root)
        return root





t = Solution()
a = binarytree.bst(3)
print(a)
print(t.convertBST(a))