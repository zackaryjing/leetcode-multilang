from queue import Queue
class Solution:
    def canVisitAllRooms(self, rooms: list[list[int]]) -> bool:
        n = len(rooms)
        vis = set()
        togo = set([0])
        while len(togo) != 0:
            # print(vis)
            temp = togo.pop()
            togo = togo.union(set(rooms[temp]) - togo - vis)
            vis.add(temp)
        return set(range(n)) == vis

t = Solution()
print(t.canVisitAllRooms([[1,3],[3,0,1],[2],[0]]))
print(t.canVisitAllRooms([[1],[2],[3],[]]))


