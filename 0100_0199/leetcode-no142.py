# Definition for singly-linked list.
class ListNode:
    def __init__(self, x, b):
        self.val = x
        self.next = b

class Solution:
    def detectcycle(self, head: [ListNode]) -> [ListNode]:
        past = []
        while head and not head in past:
            past.append(head)
            head = head.next
        if head:
            return past.index(head)
        return -1

a = None
a = ListNode(1,a)
a = ListNode(2,a)
a = ListNode(3,a)
a = ListNode(4,a)
a = ListNode(5,a)
a = ListNode(6,a)
a = ListNode(7,a)
a = ListNode(8,a)
a = ListNode(9,a)

b = None
b = ListNode(-4,b)
c = b
b = ListNode(0,b)
b = ListNode(2,b)
c.next = b
b = ListNode(3,b)



t = Solution()
print(t.detectcycle(a))
print(t.detectcycle(b))




