class MinStack2(object):
    def __init__(self):
        self.start = []
    def push(self, val):
        self.start.append(val)
    def pop(self):
        return self.start.pop()
    def top(self):
        return self.start[len(self.start)-1]
    def getMin(self):
        return min(self.start)

class MinStack(object):
    def __init__(self):
        self.start = []
    def push(self, val):
        self.start.append(val)
    def pop(self):
        return self.start.pop()
    def top(self):
        h = self.start.pop()
        self.start.append(h)
        return h
    def getMin(self):
        return min(self.start)

class MinStack(object):
    def __init__(self):
        self.start = []
        self.length = -1
    def push(self, val):
        self.start.append(val)
        self.length += 1
    def pop(self):
        self.length -= 1 if self.length >= 0 else 0
        return self.start.pop()
    def top(self):
        return self.start[self.length] if self.length >= 0 else None
    def getMin(self):
        return min(self.start)
# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
k = MinStack()
k.push(4)
k.push(5)
k.push(6)
print(k.getMin())
print(k.pop())
print(k.top())
print(k.getMin())
#["MinStack","push","push","push","getMin","pop","top","getMin"]