# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child

class Solution:
    def flatten(self, head: Node) -> Node:
        stack = []
        headc = head
        while head:
            print(head.val,"*")
            if head.child:
                stack.extend([head,head.child])
                head = head.child
            else:
                if head.next:
                    head = head.next
                elif stack:
                    a = stack.pop()
                    b = stack.pop()

                    if b.next:
                        head.next = b.next
                        b.next.prev = head
                        head = head.next
                    b.next = a
                    a.prev = b
                    b.child = None
            if (not head.next and not stack and not head.child):
                break
        return headc

t = Solution()
h5 = Node(7,None,None,None)
h1 = Node(6,None,None,None)
h2 = Node(5,None,None,None)
h3 = Node(4,None,None,None)
h4 = Node(3,None,None,None)
h6 = Node(2,None,None,None)
h7 = Node(1,None,None,None)
h1.prev = h2
h2.next = h1
h3.child = h2
h4.child = h3
h5.prev = h4
h4.next = h5
h4.prev = h6
h6.next = h4
h6.prev = h7
h7.next = h6

k = t.flatten(h7)
while k:
    print(k.val)
    k = k.next

