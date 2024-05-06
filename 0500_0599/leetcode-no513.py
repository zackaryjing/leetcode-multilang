import binarytree
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def findBottomLeftValue(self, root: TreeNode) -> int:
        utmost = [0]
        level = [-1]
        def dfs(root,lvl):
            k = 1
            if root.left:
                k = 0
                dfs(root.left,lvl+1)
            if root.right:
                k = 0
                dfs(root.right,lvl+1)
            if k:
                if lvl > level[0]:
                    utmost[0] = root.val
                    level[0] = lvl

        dfs(root,0)
        return utmost[0]

a = binarytree.tree(0)
print(a)
t = Solution()
print(t.findBottomLeftValue(a))

