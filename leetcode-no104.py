# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution2(object):
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        depths = [0]
        def dfs(root,depth):
            if root.left:
                dfs(root.left,depth+1)
            if root.right:
                dfs(root.right,depth+1)
            else:
                depths.append(depth)
        if root:
            dfs(root,1)
        return max(depths)
class Solution(object):
    def maxDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        depths = [0]
        def dfs(root,depth):
            if root.left:
                dfs(root.left,depth+1)
            if root.right:
                dfs(root.right,depth+1)
            elif depths[0] < depth:
                depths.pop()
                depths.append(depth)
        if root:
            dfs(root,1)
        return depths[0]



node6 = TreeNode(6,None,None)
node5 = TreeNode(5,None,None)
node3 = TreeNode(3,node6,node5)
node4 = TreeNode(4,None,None)
node7 = TreeNode(7,None,node4)
node2 = TreeNode(2,None,node7)
node1 = TreeNode(1,node3,node2)

Node3 = TreeNode(3,None,None)
Node2 = TreeNode(2,Node3,None)
Node1 = TreeNode(1,None,Node2)

t = Solution()
print(t.maxDepth(node1))
