from random import *
class Solution(object):

    def __init__(self, rects):
        """
        :type rects: List[List[int]]
        """
        self.rects = rects
        self.weight = []
        for rect in rects:
            self.weight.append((rect[2]-rect[0]+1)*(rect[3]-rect[1]+1))
        self.total = sum(self.weight)
        self.pos = []
        current = 0
        for i in self.weight:
            current += i
            self.pos.append(current)

    def pick(self):
        """
        :rtype: List[int]
        """
        a = randint(1,self.total-1)
        current = 0
        for t in self.pos:
            if a < t:
                return [randint(self.rects[current][0],self.rects[current][2]), \
                       randint(self.rects[current][1], self.rects[current][3])]
            current += 1

t = Solution([[-2, -2, 1, 1], [2, 2, 4, 6]])
print(t.pick())



# Your Solution object will be instantiated and called as such:
# obj = Solution(rects)
# param_1 = obj.pick()
