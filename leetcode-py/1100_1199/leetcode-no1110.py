# problem: delete-nodes-and-return-forest
from typing import *
from utils.treegenerator import *


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def delNodes(self, root: Optional[TreeNode], to_delete: List[int]) -> List[TreeNode]:
        ans: List[TreeNode] = []

        def dfs(root: Optional[TreeNode]) -> bool:
            has_left = False
            has_right = False
            if root.left:
                has_left = dfs(root.left)
            if root.right:
                has_right = dfs(root.right)
            # print(root.val, has_left, has_right)
            if not has_left:
                root.left = None
            if not has_right:
                root.right = None
            if root.val in to_delete:
                if has_left:
                    ans.append(root.left)
                if has_right:
                    ans.append(root.right)
                return False
            return True

        dfs(root)
        if root.val not in to_delete:
            ans.append(root)
        return ans


def main():
    test = Solution()
    for i in test.delNodes(stringToTreeNode("[1,2,3,4,5,6,7]"), [3, 5]):
        print(treeNodeToString(i))


if __name__ == "__main__":
    main()
