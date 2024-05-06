class Solution:
    def islandPerimeter(self, grid: list[list[int]]) -> int:
        ans = 0
        for row in grid:
            ans += sum(row)
        ans *= 2
        ans += 2
        return ans

