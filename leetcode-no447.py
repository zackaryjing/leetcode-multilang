from collections import defaultdict
class Solution(object):
    def numberOfBoomerangs(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        sum = 0
        for i in points:
            data = defaultdict(int)
            for j in points:
                length = (i[0]-j[0])**2+(i[1]-j[1])**2
                data[length] += 1
            for mid in data.values():
                sum += mid*(mid-1)
        return sum

t = Solution()
print(t.numberOfBoomerangs([[0,0],[1,0],[2,0]]))
