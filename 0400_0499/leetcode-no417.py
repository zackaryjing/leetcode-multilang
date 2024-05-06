class Solution:
    def pacificAtlantic(self, heights: list[list[int]]) -> list[list[int]]:
        candidate = []
        rows = len(heights)
        cols = len(heights[0])
        colmax = [max([t[i] for t in heights]) for i in range(cols)]
        rowmax = [max(i) for i in heights]
        print(rowmax)
        print(colmax)

        for i in range(rows):
            maxum = 0
            for j in range(cols):
                if heights[i][j] == rowmax[i] or heights[i][j] == colmax[j]:
                    candidate.append([i,j])
        return candidate

class Solution:
    def pacificAtlantic(self, heights: list[list[int]]) -> list[list[int]]:
        pacific = set()
        atlantic = set()
        rows = len(heights)
        cols = len(heights[0])
        for i in range(rows):
            for j in range(cols):
                if heights[i][j] < heights[i+1][j] or heights[i][j+1]:
                    pacific.add([i,j])

t = Solution()
print(t.pacificAtlantic([[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]))