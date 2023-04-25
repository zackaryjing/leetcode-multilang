# Definition for a binary tree node.
import binarytree
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def isSameTree(self, p:TreeNode, q:TreeNode) -> bool:
        if p == q is None:
            return True
        elif [q,p].count(None) == 1:
            return False
        def dfs(root1,root2):
            if root1.val != root2.val:
                return False
            else:
                if (p := root1.left) and (q := root2.left):
                    a = dfs(p,q)
                    if a is False:
                        return False
                else:
                    if not (root1.left == root2.left == None):
                        return False
                if ((p := root1.right) and (q := root2.right)):
                    a = dfs(p,q)
                    if a is False:
                        return False
                else:
                    if not (root1.right == root2.right == None):
                        return False
        return False if dfs(p,q) is False else True

t = Solution()
s = binarytree.tree(3)
print(t.isSameTree(s,s))

f = binarytree.tree(3)
g = binarytree.tree(3)
print(f)
print(g)
print(t.isSameTree(f,g))


