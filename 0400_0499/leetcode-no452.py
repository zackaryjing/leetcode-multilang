class Solution:
    def findMinArrowShots(self, points: list[list[int]]) -> int:
        points.sort(key=lambda x:x[1])
        lefts,rights = map(list,zip(*points))
        res = 0
        while lefts:
            res += 1
            rlimit = rights[0]
            length = len(lefts)
            pos = 0
            while pos < length:
                if lefts[pos] <= rlimit:
                    rights.pop(pos)
                    lefts.pop(pos)
                    length -= 1
                else:
                    pos += 1
        return res


class Solution:
    def findMinArrowShots(self, points: list[list[int]]) -> int:
        if not points:
            return 0

        points.sort(key=lambda ballon:ballon[1])
        pos = points[0][1]
        ans = 1
        for balloon in points:
            if balloon[0] > pos:
                pos = balloon[1]
                ans += 1
        return ans


t = Solution()
print(t.findMinArrowShots([[10,16],[2,8],[1,6],[7,12]]))
print(t.findMinArrowShots([[1,2],[3,4],[5,6],[7,8]]))
