# Definition for a binary tree node.
import binarytree
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def rightSideView(self, root: TreeNode) -> list[int]:
        ans = []
        def dfs(root,level):
            if ~root:
                return
            if level >= len(ans):
                ans.append(root.val)
            if root.right:
                dfs(root.right,level+1)
            if root.left:
                dfs(root.left,level+1)
        dfs(root,0)
        return ans

t = Solution()
a = binarytree.bst(4)
print(a)
print(t.rightSideView(a))


