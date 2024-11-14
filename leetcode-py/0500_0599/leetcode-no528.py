import random
from itertools import accumulate
class Solution:

    def __init__(self, w: list[int]):
        total = sum(w)
        self.data = []
        self.n = len(w)
        for i in accumulate(w):
            self.data.append(i/total)
        print(self.data)

    def pickIndex(self) -> int:
        x = random.random()
        # print(x)
        for j in range(self.n):
            if self.data[j] >= x:
                return j

t = Solution([1,3])

print(t.pickIndex())
print(t.pickIndex())
print(t.pickIndex())
print(t.pickIndex())
print(t.pickIndex())




# Your Solution object will be instantiated and called as such:
# obj = Solution(w)
# param_1 = obj.pickIndex()