# Definition for a binary tree node.
import binarytree


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def flatten(self, root: TreeNode) -> None:
        def dfs(root):
            end = root
            if root.left:
                end = dfs(root.left)

            if root.right:
                end.right = root.right
                print(end.val,root.val,"changes ")
                print("*"*40)
                print(root.right,end.right,"))))")
                if end != root:
                    root.right = None
                print(root.right,end.right,"((((")
                print("*"*40)
                end = dfs(end.right)
            print(root,end,"here is end ")
            # if not root.left and not root.right:
            #     return root
            # else:
            return end
        dfs(root)

        def dfs2(root):
            if root.left:
                print(root.val,"_____")
                root.right = root.left
                root.left = None
            if root.right:
                dfs2(root.right)
        dfs2(root)
        return root


class Solution:
    def flatten(self, root: TreeNode) -> None:
        if root == None:
            return
        def dfs(root):
            end = root
            if root.left:
                end = dfs(root.left)
            if root.right:
                end.right = root.right
                if end != root:
                    root.right = None
                end = dfs(end.right)
            return end
        dfs(root)

        def dfs2(root):
            if root.left:
                root.right = root.left
                root.left = None
            if root.right:
                dfs2(root.right)
        dfs2(root)

# class Solution:
#     def flatten(self, root: TreeNode) -> None:
#         """
#         Do not return anything, modify root in-place instead.
#         """
#         def dfs(root):
#             print(root.val)
#             k = 0
#             if root.right:
#                 k = 1
#                 end = dfs(root.right)
#             if root.left:
#                 k = 1
#                 end = dfs(root.left)
#                 end.right = root.right
#                 root.right = root.left
#                 root.left = None
#             print(root)
#             if k == 0:
#                 return root
#             else:
#                 return end
#
#         dfs(root)
#         return root

h2 = binarytree.tree(3)

tree = [3,1,4,None,2]
h = binarytree.build(tree)

print(h)
t = Solution()
res = t.flatten(h)
print(res)
while res:
    print(res.val)
    res = res.right
# def dfs(root, last):
#     print(root.val)
#     if root.right:
#         dfs(root.right,root)
#     if root.left:
#         dfs(root.left,root)
#     last.right = root
#
# start = TreeNode(None, None)
# dfs(root, start)
# return root
