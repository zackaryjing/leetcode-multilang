# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution(object):
    def mergeTwoLists(self, list1, list2):
        if not list1:
            return list2
        if not list2:
            return list1
        result = None
        while list1 or list2:
            if not (list1 and list2):
                while list1:
                    result = ListNode(list1.val,result)
                    list1 = list1.next
                while list2:
                    result = ListNode(list2.val,result)
                    list2 = list2.next
            else:
                if list1.val < list2.val:
                    result = ListNode(list1.val,result)
                    list1 = list1.next
                else:
                    result = ListNode(list2.val, result)
                    list2 = list2.next
        result2 = None
        while result:
            result2 = ListNode(result.val,result2)
            result = result.next
        return result2


l1 = None
for j in [4,2,1]:
    l1 = ListNode(j,l1)
l2 = None
for j in [4,3,1]:
    l2 = ListNode(j,l2)

l3 = None
for j in [4,3,2,1]:
    l3 = ListNode(j,l3)
l4 = None
for j in [8,6,4,2]:
    l4 = ListNode(j,l4)
t = Solution()
a = t.mergeTwoLists(l1,l2)
while a:
    print(a.val)
    a = a.next
print("*"*50)
s = Solution()
b = s.mergeTwoLists(l3,l4)
while b:
    print(b.val)
    b = b.next
# while l1:
#     print(l1.val)
#     l1 = l1.next