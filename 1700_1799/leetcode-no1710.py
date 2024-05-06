class Solution2(object):
    def maximumUnits(self, boxTypes, truckSize):
        """
        :type boxTypes: List[List[int]]
        :type truckSize: int
        :rtype: int
        """
        current = 0
        total = 0
        def two(li):
            return li[1]
        boxTypes.sort(key=two,reverse=True)
        length = len(boxTypes)
        while truckSize and current < length:
            total += boxTypes[current][1]
            boxTypes[current][0] -= 1
            truckSize -= 1
            if boxTypes[current][0] == 0:
                current += 1
        return total


class Solution(object):
    def maximumUnits(self, boxTypes, truckSize):
        total = 0
        current = 0
        length = len(boxTypes)
        def two(li):
            return li[1]
        boxTypes.sort(key=two,reverse=True)
        now = boxTypes[0][0]
        while True:
            total += now*boxTypes[current][1]
            truckSize -= now
            current += 1
            if current < length:
                now = boxTypes[current][0]
            else:break
            if truckSize <= now:
                break
        if current < length:
            total += boxTypes[current][1]*truckSize
        return total



t = Solution()
s = Solution2()
print(t.maximumUnits([[1,3],[2,2],[3,1]],4))
print(t.maximumUnits([[5,10],[2,5],[4,7],[3,9]],10))
print(t.maximumUnits([[1,3],[5,5],[2,5],[4,2],[4,1],[3,1],[2,2],[1,3],[2,5],[3,2]],35))
print(s.maximumUnits([[1,3],[2,2],[3,1]],4))
print(s.maximumUnits([[5,10],[2,5],[4,7],[3,9]],10))
print(s.maximumUnits([[1,3],[5,5],[2,5],[4,2],[4,1],[3,1],[2,2],[1,3],[2,5],[3,2]],35))
