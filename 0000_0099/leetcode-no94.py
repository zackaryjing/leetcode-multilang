# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        result = []
        def dfs(root):
            print(root.val)
            print(result)
            if not root.left:
                result.append(root.val)
                if root.right:
                    dfs(root.right)
            else:
                dfs(root.left)
                result.append(root.val)
                if root.right:
                    dfs(root.right)
        if root:
            dfs(root)
        return result


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
print(t.inorderTraversal(Node1))
