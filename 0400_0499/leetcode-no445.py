# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        mid1 = ""
        while l1:
            mid1 += str(l1.val)
            l1 = l1.next
        mid2 = ""
        while l1:
            mid2 += str(l2.val)
            l2 = l2.next
        temp = str(int(l1) + int(l2))
        start = None
        for i in temp[::-1]:
            start = ListNode(int(i),start)
        return start

t = Solution()
print(t.addTwoNumbers())



