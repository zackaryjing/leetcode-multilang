# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x,next=None):
        self.val = x
        self.next = next

class Solution2(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        nodes = []
        print("A B")
        while headA or headB:
            print(headA.val,headB.val)
            if headA:
                if headA not in nodes:
                    nodes.append(headA)
                else:
                    return headA.val
                headA = headA.next
            if headB:
                if headB not in nodes:
                    nodes.append(headB)
                else:
                    return headB.val
                headB = headB.next
        return None

class Solution(object):
    def getIntersectionNode(self, headA, headB):
        """
        :type head1, head1: ListNode
        :rtype: ListNode
        """
        cha,chb = headA,headB
        lengthA = lengthB = 0
        while headA:
            lengthA += 1
            headA = headA.next
        while headB:
            lengthB += 1
            headB = headB.next
        if headB == headA:
            start,late = [cha,chb] if lengthA >= lengthB else [chb,cha]
            for i in range(abs(lengthA-lengthB)):
                start = start.next
            while start != late:
                start = start.next
                late = late.next
            return start
        return None

start = None
for j in range(10):
    start = ListNode(j,start)
    if j == 7:
        k = start

for t in range(8):
    k = ListNode(t,k)

m = Solution()
print(m.getIntersectionNode(start,k))