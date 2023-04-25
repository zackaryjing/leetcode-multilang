# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def pruneTree(self, root: TreeNode) -> TreeNode:
        def dfs(root):
            if root == None:
                return 0
            r1 = r2 = 0
            if root.left:
                r1 = dfs(root.left)
            if root.right:
                r2 = dfs(root.right)
            if r1 == 0:
                root.left = None
            if r2 == 0:
                root.right = None
            if r1 or r2 or root.val:
                return 1
            else:
                return 0
        t = dfs(root)
        if not t:
            return None
        return root



# class solution:
#     def prunetree(self, root: treenode) -> treenode:
#         def dfs(root):
#             rl = rr = 0
#             if root.left:
#                 rl = dfs(root.left)
#             if root.right:
#                 rr = dfs(root.right)
#             if rl or rr:
#                 return 1
#             else:
#                 root.left = None
#                 root.right = None
#                 return 0
#         dfs(root)
#         return root

a1 = TreeNode(0,None,None,)
a2 = TreeNode(1,None,None,)
a3 = TreeNode(0,a1,a2,)
a4 = TreeNode(1,None,a3,)
t = Solution()
get = t.pruneTree(a4)
def dfs(root):
    print(root.val)
    if root.left:
        dfs(root.left)
    if root.right:
        dfs(root.right)
dfs(get)


