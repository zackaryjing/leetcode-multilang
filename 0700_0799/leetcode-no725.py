from typing import *
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
    def __str__(self):
        return str(self.val) if self else "NULL"


class Solution2:
    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        n = 0
        headcopy = head
        while head:
            head = head.next
            n += 1
        avg = n // k
        print("avg is",avg)
        greater = n - avg * k
        pos = times = 0
        ans = []
        begin = ListNode()
        while times < k:
            ans.append(headcopy)
            print(headcopy)
            if times < greater:
                ultimate = avg + 1
            else:
                ultimate = avg
            while pos < ultimate:
                print(headcopy,"from while ")
                headcopy = headcopy.next
                pos += 1
            if pos == ultimate:
                cpycpy = headcopy
                headcopy = headcopy.next
                cpycpy.next = None
                pos = 0
            times += 1
        return ans

class Solution:
    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        start = 0
        headcopy = head
        length = 0
        while headcopy:
            headcopy = headcopy.next
            length += 1
        avg = length // k
        cur,times = 0,0
        begins = []
        biggerpart = length - (k * avg)
        # print(biggerpart,length,k,avg)
        while times < k:
            begins.append(head)
            end = avg if times >= biggerpart else avg + 1
            pos = 1
            while pos < end:
                # print(times,pos,end,head.val)
                head = head.next
                pos += 1
            if head:
                tmp = head
                head = head.next
                tmp.next = None
            else:
                head = None
            times += 1
        return begins


t10 = ListNode(10,None)
t9 = ListNode(9,t10)
t8 = ListNode(8,t9)
t7 = ListNode(7,t8)
t6 = ListNode(6,t7)
t5 = ListNode(5,t6)
t4 = ListNode(4,t5)
t3 = ListNode(3,t4)
t2 = ListNode(2,t3)
t1 = ListNode(1,t2)
t = Solution()
res = t.splitListToParts(t8,5)
for test in res:
    while test:
        print(test)
        test = test.next
    print("*"*20)
# res = t.splitListToParts(t1,3)
# for test in res:
#     while test:
#         print(test)
#         test = test.next
#     print("*"*20)


