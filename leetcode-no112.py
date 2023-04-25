# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def hasPathSum(self, root: TreeNode, targetSum: int) -> bool:
        res = [False]
        if not root:
            return False
        def dfs(root,level):
            root.val += level
            k = 1
            if root.left:
                k = 0
                dfs(root.left,root.val)
            if root.right:
                k = 0
                dfs(root.right,root.val)
            if k and root.val == targetSum:
                res[0] = True
        dfs(root,0)
        return res[0]

