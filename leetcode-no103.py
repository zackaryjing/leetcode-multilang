# Definition for a binary tree node.
from collections import defaultdict
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def zigzagLevelOrder(self, root: [TreeNode]) -> list[list[int]]:
        if not root:
            return []
        res = defaultdict(list)
        def dfs(node,level):
            res[level].append(node.val)
            if node.left:
                dfs(node.left,level+1)
            if node.right:
                dfs(node.right,level+1)
        dfs(root,0)
        for i in range(len(res)):
            if i % 2 != 0:
                res[i].reverse()
        return list(res.values())



n5 = TreeNode(7,None,None)
n4 = TreeNode(25,None,None)
n3 = TreeNode(20,n4,n5)
n2 = TreeNode(9,None,None)
n1 = TreeNode(3,n2,n3)

t = Solution()
ans = t.zigzagLevelOrder(n1)
print(ans)


