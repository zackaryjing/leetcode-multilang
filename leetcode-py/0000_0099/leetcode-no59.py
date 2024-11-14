class Solution2:
    def generateMatrix(self, n: int) -> list[list[int]]:
        i = 0
        rows = 0
        cols = 0
        res = [[0]*n for i in range(n)]
        while i < n ** 2:
            while rows == 0 or res[rows][cols]:
                pass

class Solution3:
    def generateMatrix(self, n: int) -> list[list[int]]:
        res = [[0]*n for i in range(n)]
        basic = 1
        for i in range(n,0,-2):
            for j in range((n-i)//2,i+(n-i)//2):
                res[(n-i)//2][j] = basic
                basic += 1
            for k in range((n-i)//2+1,i+(n-i)//2):
                res[k][i-1] = basic
                basic += 1
            for l in range((n-i)//2+1,i+(n-i)//2):
                print("*",basic)
                res[n-1][n-l-1] = basic
                basic += 1
            for m in range((n-i)//2+2,i+(n-i)//2):
                res[n-m][(n-i)//2] = basic
                basic += 1

        return res

class Solution:
    def generateMatrix(self, n: int) -> list[list[int]]:
        depth = 0
        res = [[0]*n for i in range(n)]
        basic = 1
        for i in range((n+1)//2):
            times = n - 1 - 2 * depth
            for j in range(times):
                res[depth][depth+j] = basic
                basic += 1
                # print(res)
            for k in range(times):
                res[depth+k][n-depth-1] = basic
                basic += 1
                # print(res)
            for l in range(times):
                res[n-depth-1][n-1-depth-l] = basic
                basic += 1
                # print(res)
            for m in range(times):
                res[n-1-depth-m][depth] = basic
                basic += 1
                # print(res)
            depth += 1
        if n % 2 == 1:
            res[n//2][n//2] = n**2
        return res

t = Solution()
print(t.generateMatrix(1))
print(t.generateMatrix(2))
print(t.generateMatrix(3))
print(t.generateMatrix(4))
print(t.generateMatrix(5))



