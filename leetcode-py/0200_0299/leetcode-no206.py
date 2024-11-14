# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head:
            return None
        start = [head]
        def dfs(root,nextroot):
            if nextroot.next:
                dfs(nextroot,nextroot.next)
            else:
                start[0] = nextroot
            nextroot.next = root
        dfs(None,head)
        return start[0]

a4 = ListNode(4,None)
a3 = ListNode(3,a4)
a2 = ListNode(2,a3)
a1 = ListNode(1,a2)
t = Solution()
h = t.reverseList(a1)
while h:
    print(h.val)
    h = h.next

