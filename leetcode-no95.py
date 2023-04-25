# Definition for a binary tree node.
from collections import defaultdict
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
data = defaultdict(list)
class Solution:
    def generateTrees(self, n: int) -> list[TreeNode]:
        def dfs(node):
            k = 1
            if node.left:
                node = node.left
                k = 0
            if node.right:
                node = node.right
                k = 0
            if k:
                


        for i in range(1,n+1):
            if i != 1 and i != n:
                for j in data[i-1]:
                    for k in data[n-i]:
