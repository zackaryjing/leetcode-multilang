import binarytree
from pprint import pprint
from collections import defaultdict
from typing import *
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def printTree(self, root: Optional[TreeNode]) -> List[List[str]]:
        position = defaultdict(list)
        depth = 0
        def dfs(root:TreeNode,lvl,pos:int):
            nonlocal depth
            if lvl > depth:
                depth = lvl
            position[lvl].append([root.val,pos])
            if root.left:
                dfs(root.left,lvl+1,pos*2-1)
            if root.right:
                dfs(root.right,lvl+1,pos*2+1)
        dfs(root,1,0)
        length = 2 ** depth - 1
        ans = []
        for i in range(1,depth+1):
            tmp = [""] * length
            mv = 2 ** (depth - i)
            for node in position[i]:
                tmp[node[1] * mv + length // 2] = str(node[0])
            ans.append(tmp)
            
        return ans
      
      
# test = binarytree.tree(3)
test = binarytree.build([1,2,3,None,4])
print(test)
t = Solution()
pprint(t.printTree(test))
    