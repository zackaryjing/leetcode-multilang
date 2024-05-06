from typing import *
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution2:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        headcopy = head
        while head:
            nex = head.next
            while nex and head.val == nex.val:
                nex = nex.next
            head.next = nex
            head = head.next
        return headcopy

class Solution3:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        begin = ListNode(None,head)
        begincopy = begin
        while begin and begin.next and begin.next.next:
            print(begin.val,"-"*40)
            repeat = None
            if begin.next.val == begin.next.next.val:
                repeat = begin.val
            print(repeat,"from outer")
            nxt = begin.next
            while nxt and nxt.val == repeat:
                print(nxt.val,"from inner ***")
                nxt = nxt.next
            print(nxt.val,"end up with")
            begin.next = nxt
            begin = begin.next
        return begincopy.next

class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        begin = ListNode(None,head)
        begincopy = begin
        while begin:
            nxt = begin.next
            if nxt and nxt.next and nxt.val == nxt.next.val:
                repeat = nxt.val
            else:
                repeat = None
            # print(repeat,"from outer")
            while (nxt and nxt.val == repeat) or (nxt and nxt.next and nxt.val == nxt.next.val):
                nxt = nxt.next
                if nxt and nxt.next and nxt.val == nxt.next.val:
                    repeat = nxt.val
            begin.next = nxt
            begin = begin.next
        return begincopy.next



t10 = ListNode(8,None)
t9 = ListNode(7,t10)
t8 = ListNode(5,t9)
t7 = ListNode(5,t8)
t6 = ListNode(4,t7)
t5 = ListNode(4,t6)
t4 = ListNode(1,t5)
t3 = ListNode(1,t4)
t2 = ListNode(1,t3)
t1 = ListNode(1,t2)

s2 = ListNode(1,None)
s1 = ListNode(1,s2)

t = Solution()
res = t.deleteDuplicates(t1)
while res:
    print(res.val)
    res = res.next
