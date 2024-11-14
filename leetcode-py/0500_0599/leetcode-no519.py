import random
class Solution:
    def __init__(self, m: int, n: int):
        self.len = m * n
        self.lencopy = self.len
        self.matrix = [[0] * n for _ in range(m)]
        self.matrixcopy = self.matrix[:]
        self.avilable = [[i,j] for i in range(m) for j in range(n)]
        self.avilablecopy = self.avilable[:]

    def flip(self) -> list[int]:
        self.len -= 1
        print(self.len,self.lencopy,len(self.avilable),len(self.avilablecopy))
        x = random.randint(0,self.len)
        pick = self.avilable[x]
        self.matrix[pick[0]][pick[1]] = 1
        self.avilable.remove(pick)
        return pick

    def reset(self) -> None:
        self.matrix = self.matrixcopy[:]
        self.len = self.lencopy
        self.avilable = self.avilablecopy[:]



class Solution():

    def __init__(self,m:int,n:int):
        self.m = m
        self.n = n
        self.total = m * n
        self.map = {}

    def flip(self):
        x = random.randint(0,self.total-1)
        self.total -= 1
        idx = self.map.get(x, x)
        self.map[x] = self.map.get(self.total,self.total)
        print(x,self.map)
        return [idx//self.n,idx % self.n]

    def reset(self):
        self.total = self.m * self.n
        self.map.clear()






t = Solution(3,3)
print(t.flip())
print(t.flip())
print(t.flip())
print(t.flip())
print(t.flip())
print(t.flip())
print(t.flip())
print(t.flip())
print(t.flip())
print(t.flip())
print(t.flip())
print(t.flip())
print(t.flip())
print(t.flip())
print(t.flip())
print(t.flip())
print(t.flip())
print(t.flip())
print(t.flip())
print(t.flip())
print(t.flip())
print(t.flip())
print(t.flip())
print(t.flip())
print(t.flip())
print(t.flip())
print(t.flip())
print(t.flip())
print(t.flip())
print(t.flip())
print(t.flip())




# Your Solution object will be instantiated and called as such:
# obj = Solution(m, n)
# param_1 = obj.flip()
# obj.reset()