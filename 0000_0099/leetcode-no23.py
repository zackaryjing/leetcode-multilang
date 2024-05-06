# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

    def __str__(self):
        return str(self.val) + " " + str(self.next) + " "


t3 = ListNode(5,None)
t2 = ListNode(4,t3)
t1 = ListNode(1,t2)

a3 = ListNode(4,None)
a2 = ListNode(3,a3)
a1 = ListNode(1,a2)

b2 = ListNode(6,None)
b1 = ListNode(2,b2)

def merget2(node1:ListNode,node2:ListNode):
    if node2.val >= node1.val:
        current = node1
        theother = node2
    else:
        theother = node1
        current = node2
    ans = current
    while theother!= None and current!= None:
        if current.next == None:
            current.next = theother
            break
        if current.next.val > theother.val:
            current.next,theother = theother,current.next
        current = current.next
    return ans

# test = merget2(t1,a1)
# start = test
# while test != None:
#     print(test.val)
#     test = test.next
# print()
# test2 = merget2(start,b1)
# while test2 != None:
#     print(test2.val)
#     test2 = test2.next


class Solution:
    def mergeKLists(self, lists: list[ListNode]) -> ListNode:
        start = 0
        n = len(lists)
        while start < n and not lists[start]:
            start += 1
        # print(start,n,"((((")
        if start < n:
            last = lists[start]
        else:
            return None
        for i in range(start+1,n):
            if lists[i] != None:
                last = merget2(last,lists[i])
        return last

t = Solution()
test = t.mergeKLists([t1,a1,b1])
start = test
while test != None:
    print(test.val)
    test = test.next

h = t.mergeKLists([])
print(h)