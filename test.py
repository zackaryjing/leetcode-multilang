# a = {1,2,3}
# b = {3,1,2}
# print(a ==b)
import binarytree
# print(sum([i for i in range(1,51)])+sum([i ** 2 for i in range(1,51)])+sum([1/i for i in range(1,11)]))
# print(int("0x1f5",16))


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


a2 = TreeNode(2,None,None)
a1 = TreeNode(3,None,a2)
a1.left = a2
cpa1 = a1
cpa2 = a1
if cpa1:
    print(cpa1.val,cpa1.left.val,cpa1.right.val)


a2.right = None
if cpa2:
    print(cpa2.val,cpa2.left.val,cpa2.right.val)

end = binarytree.tree(1,is_perfect=True)
test = end
print(test)
test.left = test.right
print(test)
test.right = None
print(test)

# import binarytree
# def dfs2(root, lvl, k):
#     if depth - lvl - 1 >= 0:
#         if k >> (depth - lvl - 1) & 1:
#             if root.right:
#                 return dfs2(root.right, lvl + 1, k)
#             else:
#                 return False
#         else:
#             if root.left:
#                 return dfs2(root.left, lvl + 1, k)
#             else:
#                 return False
#     else:
#         return True
#
# # depth = 3
# # t = binarytree.tree(3)
# # print(t)
# # print(dfs2(t,0,5))
# values = [1,2,3,4,5,6,7,8,9,10,11,12]
# a = binarytree.build(values)
# print(a)
