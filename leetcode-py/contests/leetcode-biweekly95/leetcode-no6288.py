class DataStream:

    def __init__(self, value: int, k: int):
        self.value = value
        self.k = k
        self.error = k

    def consec(self, num: int) -> bool:
        if num == self.value:
            self.error -= 1
            return self.error <= 0
        else:
            self.error = self.k
            return False
t = DataStream(4,3)
print(t.consec(4))
print(t.error)
print(t.consec(4))
print(t.error)
print(t.consec(4))
print(t.error)
print(t.consec(3))
print(t.error)
print(t.consec(3))
print(t.error)
print(t.consec(3))
print(t.error)
print(t.consec(3))
print(t.error)

# Your DataStream object will be instantiated and called as such:
# obj = DataStream(value, k)
# param_1 = obj.consec(num)