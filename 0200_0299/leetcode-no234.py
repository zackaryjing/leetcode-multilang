# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution(object):
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        alist = []
        while head:
            alist.append(head.val)
            head = head.next
        return alist == [i for i in reversed(alist)]

a = None
for i in [1,2,3,4,5,3,2,1]:
    a = ListNode(i,a)

t = Solution()
print(t.isPalindrome(a))