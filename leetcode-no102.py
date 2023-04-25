# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        result = []
        def dfs(root,depth):
            if not root:
                return
            if len(result) > depth:
                result[depth].append(root.val)
            else:
                result.append([])
                result[depth].append(root.val)
            dfs(root.left,depth+1)
            dfs(root.right,depth+1)
        dfs(root,0)
        return result



node6 = TreeNode(6,None,None)
node5 = TreeNode(5,None,None)
node3 = TreeNode(3,node6,node5)
node4 = TreeNode(4,None,None)
node7 = TreeNode(7,None,node4)
node2 = TreeNode(2,None,node7)
node1 = TreeNode(1,node3,node2)

t = Solution()
print(t.levelOrder(node1))