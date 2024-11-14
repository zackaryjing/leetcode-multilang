from typing import *
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        pre = ListNode(0,head)
        backpack = pre
        times = 0
        stack = []
        cur = head
        while cur:
            if times == k:
                pre.next = stack[-1]
                for i in range(k-1):
                    tmp = stack.pop()
                    tmp.next = stack[-1]
                tmp = stack.pop()
                pre = tmp
                tmp.next = cur
                times = 0
            else:
                stack.append(cur)
                cur = cur.next
                times += 1
        if times == k:
            pre.next = stack[-1]
            for i in range(k - 1):
                tmp = stack.pop()
                tmp.next = stack[-1]
            tmp = stack.pop()
            tmp.next = None
        return backpack.next
    
node1 = ListNode(1,None)
node2 = ListNode(2,node1)
node3 = ListNode(3,node2)
node4 = ListNode(4,node3)
node5 = ListNode(5,node4)
node6 = ListNode(6,node5)
node7 = ListNode(7,node6)
node8 = ListNode(8,node7)
node9 = ListNode(9,node8)
node10 = ListNode(10,node9)
node11 = ListNode(11,node10)
node12 = ListNode(12,node11)
node13 = ListNode(13,node12)
node14 = ListNode(14,node13)
node15 = ListNode(15,node14)
node16 = ListNode(16,node15)
node17 = ListNode(17,node16)

t = Solution()
res = t.reverseKGroup(node2,2)
ttt = 17
while res:
    print(ttt,"\t",res.val)
    ttt -= 1
    res = res.next


            
            
            
        
        