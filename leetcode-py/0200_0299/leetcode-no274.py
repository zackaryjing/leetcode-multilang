class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        citations.sort(reverse=True)
        length = len(citations)
        for i in range(length):
            if i>=citations[i]:
                return i
        return length

t = Solution()
print(t.hIndex([3,0,6,1,5]))
print(t.hIndex([1]))