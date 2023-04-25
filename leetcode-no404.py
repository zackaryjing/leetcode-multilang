# Definition for a binary tree node.
import binarytree
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def sumOfLeftLeaves(self, root: TreeNode) -> int:
        ans = [0]
        if not root:
            return 0
        def dfs(root,origin):
            k = 1
            if root.left:
                k = 0
                dfs(root.left,0)
            if root.right:
                k = 0
                dfs(root.right,1)
            if k and origin == 0:
                ans[0] += root.val
        m = 0
        if root.left:
            m = 1
            dfs(root.left,0)
        if root.right:
            m = 1
            dfs(root.right,1)
        if not m:
            return 0
        return ans[0]

a = binarytree.tree()
print(a)
t = Solution()
print(t.sumOfLeftLeaves(a))