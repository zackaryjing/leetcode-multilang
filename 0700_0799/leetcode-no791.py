from collections import defaultdict
class Solution(object):
    def customSortString(self, order, s):
        """
        :type order: str
        :type s: str
        :rtype: str
        """
        length = len(order)
        result = ['']*(length+1)
        for i in s:
            if i in order:
                result[order.index(i)] += i
            else:
                result[length] += i
        return ''.join(result)

t = Solution()
print(t.customSortString("","abc"))