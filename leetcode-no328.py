from typing import *
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return None
        ends = [None,None]
        def dfs(node):
            nonlocal ends
            if node.next:
                res = dfs(node.next)
                node.next = res[1]
                if res[2] == 1:
                    ends[0] = res[0]
                    ends[1] = res[1]
                return node,res[0],res[2]+1
            else:
                return node,None,0
        head1,head2,times = dfs(head)
        if ends[1] == None:
            # print(head1.val,head2.val)
            head1.next = head2
            return head1
        if times % 2:
            ends[0].next = head2
        else:
            ends[1].next = head2
        return head1


t10 = ListNode(10, None)
t9 = ListNode(9, t10)
t8 = ListNode(8, t9)
t7 = ListNode(7, t8)
t6 = ListNode(6, t7)
t5 = ListNode(5, t6)
t4 = ListNode(4, t5)
t3 = ListNode(3, t4)
t2 = ListNode(2, t3)
t1 = ListNode(1, t2)

t = Solution()
res = t.oddEvenList(t9)
while res:
    print(res.val)
    res = res.next
# head1,head2,times = t.oddEvenList(t1)
# print(times)
# while head1:
#     print(head1.val)
#     head1 = head1.next
# print("-"*40)
# while head2:
#     print(head2.val)
#     head2 = head2.next
