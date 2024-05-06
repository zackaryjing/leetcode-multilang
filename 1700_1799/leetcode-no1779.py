class Solution(object):
    def nearestValidPoint(self, x, y, points):
        """
        :type x: int
        :type y: int
        :type points: List[List[int]]
        :rtype: int
        """
        minium = float("inf")
        pos = -1
        for i in points:
            if i[0] == x and i[1] == y:
                return points.index(i)
            elif i[0] == x:
                if abs(i[1] - y) < minium:
                    minium = abs(i[1] - y)
                    pos = points.index(i)
            elif i[1] == y:
                if abs(i[0] - x) < minium:
                    minium = abs(i[0] - x)
                    pos = points.index(i)
        return pos

t = Solution()
print(t.nearestValidPoint(3,4,[[1,2],[3,1],[2,4],[2,3],[4,4]]))
print(t.nearestValidPoint(3,4,[[3,4]]))
print(t.nearestValidPoint(3,4,[[2,3]]))
