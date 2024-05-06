# Definition for a Node.
from typing import *
import binarytree
from collections import defaultdict
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next

class Solution:
    def connect(self, root: 'Optional[Node]') -> 'Optional[Node]':
        if not root:
            return root
        ptr = defaultdict(Node)
        # print(ptr[0])
        def dfs(root,lvl):
            if ptr[lvl]:
                # print("here")
                ptr[lvl].next = root
                ptr[lvl] = root
            else:
                ptr[lvl] = root
            if root.left:
                dfs(root.left,lvl+1)
            if root.right:
                dfs(root.right,lvl+1)
        dfs(root,0)
        return root
        
t = Solution()
# test = binarytree.tree(3,is_perfect=True)
Node7 = Node(7)
Node6 = Node(6)
Node5 = Node(5)
Node4 = Node(4)
Node3 = Node(3,Node6,Node7)
Node2 = Node(2,Node4,Node5)
Node1 = Node(1,Node2,Node3)

ans = defaultdict(list)
def bfs(root,lvl):
    ans[lvl].append("%d -> %d" %(root.val,root.next.val if root.next else -1))
    if root.left:
        bfs(root.left,lvl+1)
    if root.right:
        bfs(root.right,lvl+1)
        
bfs(t.connect(Node1),0)
for key,value in ans.items():
    print(value)
    

