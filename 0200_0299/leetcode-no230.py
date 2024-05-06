# Definition for a binary tree node.
# python -m install ...
from binarytree import bst
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        res = []
        def inorder(root):
            if root.left:
                inorder(root.left)
            res.append(root.val)
            if root.right:
                inorder(root.right)
        inorder(root)
        return res[k-1]

a = bst(height=3,is_perfect=False)
print(a)
t = Solution()
print(t.kthSmallest(a,3))
