# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return head
        if not head.next:
            return head
        copyhead = head.next
        while head and head.next:
            second = head.next
            if head.next.next:
                third = head.next.next
                if head.next.next.next:

                    head.next = head.next.next.next
                else:
                    head.next = head.next.next
            else:
                head.next = None
                third = None
            second.next = head
            head = third
        return copyhead



l2 = None
for i in [1,2,3,4]:
    l2 = ListNode(i,l2)

t = Solution()
h = t.swapPairs(l2)
while h:
    print(h.val)
    h = h.next


