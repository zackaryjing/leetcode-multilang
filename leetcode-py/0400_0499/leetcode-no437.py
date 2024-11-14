# Definition for a binary tree node.
import binarytree
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def pathSum(self, root: TreeNode, targetSum: int) -> int:
        # def dfs1(root,value):
        #     root.val += value
        #     if root.left:
        #         dfs1(root.left,root.val)
        #     if root.right:
        #         dfs1(root.right,root.val)
        # dfs1(root,0)
        res = 0
        # print(root)
        def dfs2(root,target):
            nonlocal res
            if not root:
                return
            if target - root.val == 0:
                res += 1
            if root.left:
                dfs2(root.left,target-root.val)
            if root.right:
                dfs2(root.right,target-root.val)
        def dfs(root):
            dfs2(root, targetSum)
            if root.left:
                dfs(root.left)
            if root.right:
                dfs(root.right)
        dfs(root)
        return res

t = Solution()
a = binarytree.bst(3)
print(a)
tar = int(input("> "))
print(t.pathSum(a,tar))


