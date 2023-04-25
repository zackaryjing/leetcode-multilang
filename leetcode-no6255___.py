from collections import defaultdict
class PathNodes():
    def __init__(self):
        pass
class Solution:
    def minScore(self, n: int, roads: list[list[int]]) -> int:
        paths = defaultdict(set)
        roads.sort()
        for i in roads:
            paths[i[0]].add([i[1],i[2]])
            paths[i[1]].add([i[0],i[2]])
        nums = max(sum([i[:2] for i in roads],[]))
        data = defaultdict(list)
        for i in range(1,nums):
            data[i] = [float('inf'),False]
        current = 1
        while data[current[1]]:
            for j in paths[current]:
                pass

class Solution:
    '''
    使用优先级队列，dijkstra算法。
    '''
    def minScore(self, n: int, roads: list[list[int]]) -> int:
        paths = defaultdict(set)
        roads.sort()
        for i in roads:
            paths[i[0]].add([i[1], i[2],float('inf'),False])
            paths[i[1]].add([i[0], i[2],float('inf'),False])
        priorityqueue = []
        current = 1
        priorityqueue.extend(list(paths[current]))
        while priorityqueue:
            for node in priorityqueue:
                if node[2]>node[1]:
                    node[2]=node[1]
                    node[3]=True
                priorityqueue.remove(node)
                for i in paths[current]:
                    if not i in priorityqueue and i[3]:
                        priorityqueue.append(i)




t = Solution()
print(t.minScore(4,[[1,2,9],[2,3,6],[2,4,5],[1,4,7]]))