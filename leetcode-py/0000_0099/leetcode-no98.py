# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def isValidBST(self, root:[TreeNode]) -> bool:
        istree = [True]
        def dfs(node):
            hasson = 0
            leftmin = rightmin = float('inf')
            leftmax = rightmax = float('-inf')
            if node.left:
                hasson = 1
                leftmin,leftmax = dfs(node.left)
                if leftmax >= node.val:
                    istree[0] = False
            if node.right:
                hasson = 1
                rightmin,rightmax = dfs(node.right)
                if rightmin <= node.val:
                    istree[0] = False
            if not hasson:
                return node.val,node.val
            return min(leftmin,rightmin,node.val),max(leftmax,rightmax,node.val)
        dfs(root)
        return istree[0]


n5 = TreeNode(7, None, None)
n4 = TreeNode(25, None, None)
n3 = TreeNode(20, n4, n5)
n2 = TreeNode(9, None, None)
n1 = TreeNode(3, n2, n3)

s5 = TreeNode(6, None, None)
s4 = TreeNode(3, None, None)
s3 = TreeNode(4, s4, s5)
s2 = TreeNode(1, None, None)
s1 = TreeNode(5, s2, s3)
t = Solution()

k3 = TreeNode(3,None,None)
k2 = TreeNode(1,None,None)
k1 = TreeNode(2,k2,k3)
print(t.isValidBST(n1))
print(t.isValidBST(s1))
print(t.isValidBST(k3))
