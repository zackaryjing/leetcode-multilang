# problem: all-possible-full-binary-trees
from functools import lru_cache, cache
from typing import *
from utils.treegenerator import *


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    @cache
    def create(self, n: int) -> List[Optional[TreeNode]]:
        res: List[Optional[TreeNode]] = []
        if n == 1:
            return [TreeNode(0)]
        for i in range(1, n - 1, 2):
            lefts = self.create(i)
            rights = self.create(n - 1 - i)
            for left in lefts:
                for right in rights:
                    res.append(TreeNode(0, left, right))
        return res

    def allPossibleFBT(self, n: int) -> List[Optional[TreeNode]]:
        if n % 2 == 0:
            return []
        return self.create(n)


def main():
    test = Solution()
    for i in test.allPossibleFBT(7):
        print(treeNodeToString(i))


# [[0,0,0,null,null,0,0,null,null,0,0]
# [0,0,0,null,null,0,0,0,0]
# [0,0,0,0,0,0,0]
# [0,0,0,0,0,null,null,null,null,0,0]
# [0,0,0,0,0,null,null,0,0]]

if __name__ == "__main__":
    main()
