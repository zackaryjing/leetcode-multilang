class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        first = [[1]]
        temp = [1]
        for i in range(1, rowIndex+1):
            temp = [1]
            for j in range(i - 1):
                temp.append(first[j] + first[j + 1])
            temp.append(1)
            first = temp
        return temp

t = Solution()
print(t.getRow(0))