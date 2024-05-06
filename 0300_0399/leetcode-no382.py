# Definition for singly-linked list.
from random import randint
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:

    def __init__(self, head: ListNode):
        self.nodes = []
        while head:
            self.nodes.append(head.val)
            head = head.next
        self.n = len(self.nodes)

    def getRandom(self) -> int:
        return self.nodes[randint(0,self.n-1)]

a1 = ListNode(3,None)
a2 = ListNode(2,a1)
a3 = ListNode(1,a2)
t = Solution(a3)
for i in range(100):
    print(t.getRandom())

# Your Solution object will be instantiated and called as such:
# obj = Solution(head)
# param_1 = obj.getRandom()