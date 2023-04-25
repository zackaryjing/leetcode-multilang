class Solution:
    def calculateMinimumHP(self, dungeon: list[list[int]]) -> int:
        n = len(dungeon)
        m = len(dungeon[0])
        for i in range(0,n):
            if i == 0:
                for j in range(1,m):
                    dungeon[0][j] += dungeon[0][j-1]
            else:
                dungeon[i][0] += dungeon[i-1][0]
                for k in range(1,m):
                    dungeon[i][k] += max(dungeon[i-1][k],dungeon[i][k-1])

        for i in dungeon:
            print(i)
        print("-"*50)
        for i in range(0,n):
            if i == 0:
                for j in range(1,m):
                    dungeon[0][j] = min(dungeon[0][j-1],dungeon[0][j])
            else:
                dungeon[i][0] = min(dungeon[i-1][0],dungeon[i][0])
                for k in range(1,m):
                    dungeon[i][k] = min(dungeon[i][k],max(dungeon[i-1][k],dungeon[i][k-1]))

        for i in dungeon:
            print(i)
        return abs(dungeon[-1][-1])+1

t = Solution()
a = t.calculateMinimumHP([[-2,-3,3],[-5,-10,1],[10,30,-5]])
print(a)
# for t in a:
#     print(t)

