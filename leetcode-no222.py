# Definition for a binary tree node.
import binarytree


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def countNodes(self, root: TreeNode) -> int:
        if not root:
            return 0
        depth = 0
        def dfs(root,lvl):
            nonlocal depth
            if root.left:
                dfs(root.left,lvl+1)
            else:
                depth = lvl
        dfs(root,0)
        def dfs2(root, lvl, k):
            if depth - lvl - 1 >= 0:
                if k >> (depth - lvl - 1) & 1:
                    if root.right:
                        return dfs2(root.right, lvl + 1, k)
                    else:
                        return False
                else:
                    if root.left:
                        return dfs2(root.left, lvl + 1, k)
                    else:
                        return False
            else:
                return True
        dfs(root,0)
        left = 0
        right = 2 ** depth - 1
        while left < right:
            print(left,right)
            mid = (left + right + 1)//2
            if dfs2(root,0,mid):
                left = mid
            else:
                right = mid - 1
        return bin(left),left,2 ** depth + left

t = Solution()
values = []
a = binarytree.build(values)
print(a)
print(t.countNodes(a))




