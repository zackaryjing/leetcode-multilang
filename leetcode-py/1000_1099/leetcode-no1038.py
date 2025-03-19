# problem: binary-search-tree-to-greater-sum-tree/
from typing import *

from utils.treegenerator import *


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.sum = 0

    def dfs(self, root: Optional[TreeNode]):
        if root.right:
            self.dfs(root.right)
        self.sum += root.val
        root.val = self.sum

        if root.left:
            self.dfs(root.left)

    def bstToGst(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        self.dfs(root)
        return root


def main():
    test = Solution()
    print(treeNodeToString(test.bstToGst(stringToTreeNode("[4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]"))))


if __name__ == "__main__":
    main()
