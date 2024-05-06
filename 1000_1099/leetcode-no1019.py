# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def nextLargerNodes(self, head: ListNode) -> list[int]:
        stack = []
        ans = []
        current = 0
        while head != None:
            while len(stack) != 0 and head.val > stack[-1][1]:
                print(head.val,"from bigger")
                ans.append([stack.pop()[0],head.val])
            if len(stack) == 0 or head.val <= stack[-1][1]:
                print(head.val,"from less")
                stack.append([current,head.val])
            head = head.next
            current += 1
        ans += [[i[0],0] for i in stack]
        ans.sort()
        return [i[1] for i in ans]

t7 = ListNode(5,None)
t6 = ListNode(2,t7)
t5 = ListNode(5,t6)
t4 = ListNode(3,t5)
t3 = ListNode(4,t4)
t2 = ListNode(7,t3)
t1 = ListNode(2,t2)

t = Solution()
print(t.nextLargerNodes(t1))






