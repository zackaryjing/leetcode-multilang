# Definition for a binary tree node.
from collections import defaultdict
import binarytree
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def levelOrderBottom(self, root: TreeNode) -> list[list[int]]:
        if not root:
            return []
        ans = defaultdict(list)
        def dfs(root,lvl):
            ans[lvl].append(root.val)
            if root.left:
                dfs(root.left,lvl+1)
            if root.right:
                dfs(root.right,lvl+1)
        dfs(root,0)
        return list(reversed(ans.values()))

a = binarytree.tree(3)
t = Solution()
print(a)
print(t.levelOrderBottom(a))