class Solution2(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[List[int]]
        :type newInterval: List[int]
        :rtype: List[List[int]]
        """
        done1 = True
        done2 = True
        for i in range(len(intervals)):
            if done1 and intervals[i][1] > newInterval[0] >= intervals[i][0]:
                start = intervals[i][0]
                here = i
                done1 = False
            if done2 and intervals[i][1] > newInterval[1] >= intervals[i][0]:
                end = intervals[i][1]
                done2 = False
                there = i
        return intervals[:here]+[[start,end]]+intervals[there+1:]

class Solution(object):
    def insert(self, intervals, newInterval):
        """
        :type intervals: List[List[int]]
        :type newInterval: List[int]
        :rtype: List[List[int]]
        """
        
t = Solution()
print(t.insert([[1,2],[3,5],[6,7],[8,10],[12,16]],[4,8]))
print(t.insert([[1,3],[6,9]],[2,5]))
