class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution2(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        value = []
        while head:
            if not(head.val in value):
                value.append(head.val)
            head = head.next
        result = None
        for i in sorted(value,reverse=True):
            result = ListNode(i,result)
        return result


class Solution(object):
    def deleteDuplicates(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        node = head
        if not head:
            return head
        while head.next:
            if not head.next == None:
                if head.val == head.next.val:
                    head.next = head.next.next
                else:
                    head = head.next
        return node

a = [4,4,3,3,2,1,1]
test = None
for i in a:
    test = ListNode(i,test)

t = Solution()
h = t.deleteDuplicates(test)
while h:
    print(h.val)
    h = h.next
