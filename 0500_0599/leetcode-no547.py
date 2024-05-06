from functools import cache
class Solution:
    def findCircleNum(self, isConnected: list[list[int]]) -> int:
        n = len(isConnected)
        pre = list(range(n))
        def find(num):
            if pre[num] == num:
                return num
            return find(pre[num])
        @cache
        def find2(num):
            if pre[num] == num:
                return num
            return find(pre[num])
        def union(a,b):
            pre[find(b)] = find(a)

        for i in range(n):
            for j in range(i+1,n):
                if isConnected[i][j]:
                    union(i,j)
        for i in range(n):
            pre[i] = find2(i)
        return len(set(pre))

t = Solution()
print(t.findCircleNum([[1,1,0],[1,1,0],[0,0,1]]))
print(t.findCircleNum([[1,0,0],[0,1,0],[0,0,1]]))
print(t.findCircleNum([
    [1,0,1,0,0],\
    [0,1,0,0,1],\
    [0,0,1,1,0],\
    [0,0,0,1,0],\
    [0,0,0,0,1]\
]))
print(t.findCircleNum([
    [1,0,0,0,1], \
    [0,1,0,1,0], \
    [0,0,1,0,1], \
    [0,0,0,1,0], \
    [0,0,0,0,1] \
    ]))
print(t.findCircleNum([
    [1,1,1,1,1], \
    [0,1,1,1,1], \
    [0,0,1,1,1], \
    [0,0,0,1,1], \
    [0,0,0,0,1] \
    ]))
print(t.findCircleNum([
    [1,0,0,1,0], \
    [0,1,1,0,1], \
    [0,0,1,0,1], \
    [0,0,0,1,1], \
    [0,0,0,0,1] \
    ]))
'''
[1,0,0,1,0]
[0,1,0,1,1]
[0,0,1,0,0]
[0,0,0,1,0]
[0,0,0,0,1]

[0, 0, 2]
[0, 1, 2]
[0, 1, 0, 0, 1]
[2, 1, 2, 1, 0]

[0, 0, 2]
[0, 1, 2]
[0, 1, 0, 0, 1]
[0, 1, 2, 1, 2]
'''
