from collections import deque
class MyQueue:
    def __init__(self):
        self.inval = []
        self.outval = []

    def push(self, x: int) -> None:
        self.inval.append(x)

    def pop(self) -> int:
        if not self.outval:
            while self.inval:
                self.outval.append(self.inval.pop())
        return self.outval.pop()

    def peek(self) -> int:
        if not self.outval:
            while self.inval:
                self.outval.append(self.inval.pop())
        return self.outval[-1]


    def empty(self) -> bool:
        return self.inval == [] and self.outval == []



# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()