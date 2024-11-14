# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution(object):
    def reverseBetween(self, head, left, right):
        """
        :type head: ListNode
        :type left: int
        :type right: int
        :rtype: ListNode
        """
        current = 1
        copyhead = first_part_end = third_part_begin = head
        middlepart = []
        while head:
            if current == left - 1:
                first_part_end = head
            elif current == right + 1:
                third_part_begin = head
            if left <= current <= right:
                middlepart.append(head)
            current += 1
            head = head.next
        print(current,"*****")
        for i in range(right - left, 0, -1):
            middlepart[i].next = middlepart[i - 1]
        if left == right:
            return copyhead
        if left == 1 and right == current-1:
            print("yes")
            middlepart[0].next = None
            return middlepart[-1]
        if left == 1:
            middlepart[0].next = third_part_begin
            return middlepart[-1]
        if right == current-1:
            first_part_end.next = middlepart[-1]
            return copyhead
        first_part_end.next = middlepart[-1]
        middlepart[0].next = third_part_begin
        return copyhead

# a = None
# for i in range(7,0,-1):
#     a = ListNode(i,a)
# t = Solution()
# b = t.reverseBetween(a,2,4)
# while b:
#     print(b.val)
#     b = b.next

c = None
c = ListNode(5,c)
c = ListNode(3,c)
t = Solution()
res = t.reverseBetween(c,1,2)
while res:
    print(res.val)
    res = res.next
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# class Solution(object):
#     def reverseBetween(self, head, left, right):
#         """
#         :type head: ListNode
#         :type left: int
#         :type right: int
#         :rtype: ListNode
#         """
#
#         secondpart = []
#         current = 1
#         while head:
#             if current == left:
#                 first_part_end =
#             if current <= right:
#                 secondpart.append(head)
#                 head = head.next
#                 current += 1
#         for i in