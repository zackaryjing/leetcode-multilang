# Definition for a binary tree node.
import binarytree
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def longestUnivaluePath(self, root:TreeNode) -> int:
        if not root:
            return 0
        maxum = [0]
        def dfs(root,length):
            if length > maxum[0]:
                maxum[0] = length
            if root.left:
                # print("left")
                if root.val != root.left.val:
                    if length > maxum[0]:
                        maxum[0] = length
                    dfs(root.left,1)
                else:
                    dfs(root.left,length + 1)
            if root.right:
                # print("right")
                if root.val != root.right.val:
                    if length > maxum[0]:
                        maxum[0] = length
                    dfs(root.right,1)
                else:
                    dfs(root.right,length + 1)
        dfs(root,0)
        return maxum[0]

class Solution:
    def longestUnivaluePath(self, root:TreeNode) -> int:
        maxum = [0]
        if not root:
            return 0
        def dfs(root):
            current = 0
            larger = 0
            if root.left:
                # print("left")
                a = dfs(root.left)
                if root.val == root.left.val:
                    current += a + 1
                    larger = a + 1
            if root.right:
                # print("right")
                b = dfs(root.right)
                if root.val == root.right.val:
                    current += b + 1
                    if b + 1 > larger:
                        larger = b + 1
            if current > maxum[0]:
                maxum[0] = current
            return larger
        dfs(root)
        return maxum[0]


a1 = TreeNode(5,None,None)
a2 = TreeNode(1,None,None)
a3 = TreeNode(1,None,None)
a4 = TreeNode(5,None,a1)
a5 = TreeNode(4,a2,a3)
a6 = TreeNode(5,a5,a4)

t = Solution()
print(t.longestUnivaluePath(a6))