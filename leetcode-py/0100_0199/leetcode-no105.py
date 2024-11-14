# Definition for a binary tree node.
import binarytree
from typing import *
from collections import defaultdict
from binarytree import Node
class TreeNode(Node):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        super(TreeNode,self).__init__(self.val)
        
        
class Solution2:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        n = len(preorder)
        precur = 1
        incur = 0
        root = TreeNode(val=preorder[0])
        copy = root
        vis = set([preorder[0]])
        def dfs(root):
            nonlocal precur,incur
            print(copy,root.val,inorder[incur])
            # print(root.val,inorder[incur])
            if precur < n and root.val != inorder[incur]:
                # print("hello")
                tmp = TreeNode(preorder[precur])
                vis.add(preorder[precur])
                root.left = tmp
                precur += 1
                dfs(root.left)
                incur += 1
            else:
                incur += 1
                return
            # incur += 1
            print("back",root.val,incur + 1 >= n,incur)
            # if precur < n and (incur + 1 >= n or inorder[incur+1] not in vis):
            if not inorder[incur + 1] in vis:
                tmp = TreeNode(preorder[precur])
                vis.add(preorder[precur])
                root.right = tmp
                precur += 1
                dfs(root.right)
        dfs(root)
        return root
    
    
class Solution():
    def buildTree(self,preorder: List[int], inorder: List[int]) -> TreeNode:
        if not preorder:
            return None
        
        root = TreeNode(preorder[0])
        stack = [root]
        inorderIndex = 0
        for i in range(1,len(preorder)):
            preorderVal = preorder[i]
            node = stack[-1]
            if node.val != inorder[inorderIndex]:
                node.left = TreeNode(preorderVal)
                stack.append(node.left)
            else:
                while stack and stack[-1].val == inorder[inorderIndex]:
                    node = stack.pop()
                    inorderIndex += 1
                node.right = TreeNode(preorderVal)
                stack.append(node.right)
        return root
        
            
            
            
t = Solution()
a = t.buildTree([3,9,20,15,7],[9,3,15,20,7])
print(a)
a = t.buildTree([1,2,3,4,6,7],[4,3,2,1,6,7])
print(a)

#   3
#  / \
# 9   20
#  20 15
#
#   3___
#  /    \
# 9     _20
#      /
#     15
#  15 15
########################################
#   3
#  / \
# 9   20
#  20 3
#
#   3___
#  /    \
# 9     _20
#      /
#     15
#  15 3
#
#   3_____
#  /      \
# 9       _20
#        /
#       15
#      /
#     7
#  7 3

# ans = defaultdict(list)
# def dfs(root,lvl):
#     print(lvl)
#     ans[lvl].append(root.val)
#     if root.left:
#         dfs(root.left,lvl+1)
#     if root.right:
#         dfs(root.right,lvl+1)
#
# dfs(a,0)
#
# for key,value in ans.items():
#     print(key,value)




            
        
        
            