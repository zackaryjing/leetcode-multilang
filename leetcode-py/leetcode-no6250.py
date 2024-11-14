class Solution(object):
    def bestClosingTime(self, customers):
        """
        :type customers: str
        :rtype: int
        """
        result = []
        length = len(customers)
        presum = 0
        for i in range(length):
            later = 0
            for j in range(i,length):
                later += customers[j]=="Y"
            result.append(presum+later)
            presum += customers[i]=="N"
        result.append(presum)
        return result.index(min(result))


class Solution(object):
    def bestClosingTime(self, customers):
        """
        :type customers: str
        :rtype: int
        """
        result = []
        length = len(customers)
        presum = 0
        later = customers.count("Y")
        for i in range(length):
            result.append(presum+(customers[i]=="Y")+later)
            presum += customers[i]=="N"
            later -= customers[i]=="Y"
        result.append(presum)
        return result.index(min(result))

t = Solution()
print(t.bestClosingTime("YYNY"))
print(t.bestClosingTime("YYYY"))
print(t.bestClosingTime("NNNN"))
