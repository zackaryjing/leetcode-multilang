# Definition for a binary tree node.
import binarytree
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def binaryTreePaths(self, root: TreeNode) -> str:
        routine = []
        if not root:
            return []
        def dfs(root,path):
            k = 0
            if root.left:
                k = 1
                dfs(root.left,path+"->"+str(root.val))
            if root.right:
                k = 1
                dfs(root.right,path+"->"+str(root.val))
            if not k:
                routine.append((path+"->"+str(root.val))[2:])
        dfs(root,"")
        return routine
t = Solution()
a = binarytree.tree(3)
print(a)
print(t.binaryTreePaths(a))



