# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        num1 = 0
        num2 = 0
        times = 0
        while l1 != None or l2 != None:
            if l1 != None:
                num1 += 10**times*l1.val
                l1 = l1.next
            if l2 != None:
                num2 += 10 ** times * l2.val
                l2 = l2.next
            times += 1
        num3 = num1 + num2
        temp = ListNode(0)
        head = temp
        for i in reversed(str(num3)):
            temp.next = ListNode(int(i))
            temp = temp.next
        return head.next


l1 = None
for i in [3,4,2]:
    l1 = ListNode(i,l1)
l2 = None
for i in [4,6,5]:
    l2 = ListNode(i,l2)


t = Solution()
a = t.addTwoNumbers(l1,l2)
while a:
    print(a.val)
    a = a.next
