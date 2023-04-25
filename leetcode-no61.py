# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def rotateRight(self, head: [ListNode], k: int) -> [ListNode]:
        if not head:
            return head
        nodes = []
        while head:
            nodes.append(head)
            head = head.next
        n = len(nodes)
        if n == 1:
            return head
        k %= n
        nodes[-1].next = nodes[0]
        nodes[n-1-k].next = None
        return nodes[(n-k)%n]


n1 = ListNode(5,None)
n2 = ListNode(4,n1)
n3 = ListNode(3,n2)
n4 = ListNode(2,n3)
n5 = ListNode(1,n4)
# n6 = ListNode(6,n5)

t = Solution()
a = t.rotateRight(n1,0)
while a:
    print(a.val)
    a = a.next