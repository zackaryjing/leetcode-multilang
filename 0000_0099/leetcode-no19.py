# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution2(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        nodes = []
        t = head
        while head:
            nodes.append(head)
            head = head.next
        length = len(nodes)
        if length == 1 and n == 1:
            return None
        if not (n == 1 or n == length):
            nodes[length-n-1].next = nodes[length-n+1]
        elif n == 1:
            nodes[length-2].next = None
        else:
            return nodes[1]
        return t

#include<bits/stdc++.h>

class Solution(object):
    def removeNthFromEnd(self, head, n):
        length = 0
        t = head
        x = head
        while head:
            length += 1
            head = head.next
        current = 1
        while t:
            if current == length - n and n != 1 and n != length:
                t.next = t.next.next
            elif n == 1 and current == length - 1 :
                t.next = None
                return x
            elif n == length:
                return t.next
            t = t.next
            current += 1
        return x
l2 = None
for i in [5,4,3,2,1]:
    l2 = ListNode(i,l2)

t = Solution()
h = t.removeNthFromEnd(l2,5)
while h:
    print(h.val)
    h = h.next


