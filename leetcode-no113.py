# Definition for a binary tree node.
import binarytree
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def pathSum(self, root: TreeNode, targetSum: int) -> list[list[int]]:
        if not root:
            return []
        res = []
        def dfs(root,presum,path):
            isleaf = True
            if root.left:
                dfs(root.left,presum + root.val,path+[root.val])
                isleaf = False
            if root.right:
                dfs(root.right,presum + root.val,path+[root.val])
                isleaf = False
            if isleaf and (presum + root.val) == targetSum:
                res.append(path+[root.val])
        dfs(root,0,[])
        return res

t = Solution()
a = binarytree.tree()
print(a)
sum = int(input(">>> "))
print(t.pathSum(a,sum))



