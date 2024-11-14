# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        depths = [float('inf')]
        def dfs(root, depth):
            if root.left:
                dfs(root.left, depth + 1)
            if root.right:
                dfs(root.right, depth + 1)
            elif not root.left and depths[0] > depth:
                depths.pop()
                depths.append(depth)
        if root:
            dfs(root, 1)
            return depths[0]
        return 0