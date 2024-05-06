from typing import *
import binarytree
import math
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'Treenode', p: 'Treenode', q: 'Treenode') -> 'Treenode':
        ans = root
        def dfs(root):
            nonlocal ans
            if (root == None):
                return False
            lson = dfs(root.left);
            rson = dfs(root.right)
            if (lson and rson) or ((root.val == p.val or root.val == q.val) and (lson or rson)):
                ans = root
            return lson or rson or (root.val == p.val or root.val == q.val)
        dfs(root)
        return ans

class Solution3:
    def lowestCommonAncestor(self, root: 'Treenode', p: 'Treenode', q: 'Treenode') -> 'Treenode':
        found = 0
        def getpos(pos1,pos2):
            while pos1 != pos2:
                if pos1 > pos2:
                    pos1 //= 2
                else:
                    pos2 //= 2
            return pos1
        positions = []
        found = 0
        tofind = 0

        def add(num):
            nonlocal found,tofind
            positions.append(num)
            found += 1
            if found == 2:
                tofind = getpos(*positions)
        ans = root
        def dfs(root,pos):
            nonlocal ans
            if root == p or root == q:
                add(pos)
            if root.left:
                dfs(root.left,pos*2)
            if root.right:
                dfs(root.right,pos*2+1)
            if pos == tofind:
                ans = root
                return
        dfs(root,1)
        return ans


class Solution2:
    def lowestcommonancestor(self, root: 'treenode', p: 'treenode', q: 'treenode') -> 'treenode':

        def dfs(root,pos,target):
            if root == target:
                return pos
            expleft = expright = None
            if root.left:
                expleft = dfs(root.left,pos*2,target)
            if expleft:
                return expleft
            if root.right:
                expright = dfs(root.right,pos*2+1,target)
            if expright:
                return expright
            return None
        pos1 = dfs(root,1,p)
        pos2 = dfs(root,1,q)
        while pos1 != pos2:
            if pos1 > pos2:
                pos1 //= 2
            else:
                pos2 //= 2
        n = 1
        while pos2 > 1:
            n += 1
            pos2 //= 2
        for j in range(n-2,-1,-1):
            if (pos1 >> j) & 1:
                root = root.right
            else:
                root = root.left
        return root


def dfs(root,target):
    if root.val == target:
        return root
    expleft = expright = None
    if root.left:
        expleft = dfs(root.left,target)
    if expleft:
        return expleft
    if root.right:
        expright = dfs(root.right,target)
    if expright:
        return expright
    return None

test = binarytree.build([3,5,1,6,2,0,8,None,None,7,4])
print(test)
test1 = dfs(test,6)
test2 = dfs(test,2)
print(test1)
print(test2)
t = Solution()
a = t.lowestCommonAncestor(test,test1,test2)
print(a)
