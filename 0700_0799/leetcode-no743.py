''' dijkstra '''
from queue import Queue
from collections import defaultdict
class Solution:
    def networkDelayTime(self, times: list[list[int]], n: int, k: int) -> int:
        routes = defaultdict(list)
        for i in times:
            routes[i[0]].append(i[1:])
        routes[0] = [k,0]
        visited = [float('inf')] * (n + 1)
        tobevis = Queue()
        tobevis.put(k)
        nest = 0
        visited[0] = 0
        while not tobevis.empty():
            current = visited[nest]
            print(visited,"vis",current,nest)
            print(routes[nest])
            nest = tobevis.get()
            for i in routes[nest]:
                print(i[1],current)
                if visited[i[0]] == float('inf'):
                    tobevis.put(i[0])
                if (current + i[1]) < visited[i[0]]:
                    print(current + i[1],visited[i[0]],"))")
                    visited[i[0]] = current + i[1]
        print(visited[1:])
        return -1 if (float('inf') in visited[1:]) else max(visited[1:])

t = Solution()
print(t.networkDelayTime([[1,2,1],[2,3,2]],3,1))
# print(t.networkDelayTime([[2,1,1],[2,3,1],[3,4,1]],4,2))
# print(t.networkDelayTime([[1,2,1]], n = 2, k = 1))
# print(t.networkDelayTime([[1,2,1]], n = 2, k = 2))


