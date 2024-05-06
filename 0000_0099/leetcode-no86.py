from functools import cmp_to_key
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def partition(self, head: [ListNode], x: int) -> [ListNode]:
        nodes = []
        while head:
            nodes.append(head)
            head = head.next
        nodes.sort(key=cmp_to_key(lambda a,b:0 \
            if ((a.val >= x and b.val >= x) or \
               (a.val < x and b.val < x)) else a.val-b.val))
        for i in range(len(nodes)):
            nodes[i].next = nodes[i+1] if i < len(nodes)-1 else None
        return nodes[0] if nodes else None

n6 = ListNode(2,None)
n5 = ListNode(5,n6)
n4 = ListNode(2,n5)
n7 = ListNode(0,n4)
n3 = ListNode(3,n7)
n2 = ListNode(4,n3)
n1 = ListNode(1,n2)

t = Solution()
ans = t.partition(n1,3)
while ans:
    print(ans.val)
    ans = ans.next

'''
[1,4,3,0,2,5,2]
'''