# Definition for a binary tree node.
import queue
import binarytree
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def largestValues(self, root: TreeNode) -> list[int]:
        if not root:
            return []
        a = queue.Queue()
        a.put([root,0])
        current = []
        now = 0
        res = []
        while not a.empty():
            # print(h := a.get())
            root,level = h
            if level != now:
                res.append(max(current))
                current = [root.val]
            else:
                current.append(root.val)
            now = level
            if b := root.left:
                a.put([b,level+1])
            if b := root.right:
                a.put([b,level+1])
        res.append(max(current))
        return res

t = Solution()
s = binarytree.tree(3)
print(s)
print(t.largestValues(s))
