import random
class Solution:
    def __init__(self, radius: float, x_center: float, y_center: float):
        self.radius = radius
        self.x_center = x_center
        self.y_center = y_center

    def randPoint(self) -> list[float]:
        while True:
            x = (random.random()-0.5)*2
            y = (random.random()-0.5)*2
            print(x,y)
            if (x ** 2 + y ** 2) <= 1:
                return [x*self.radius+self.x_center,y*self.radius+self.y_center]

t = Solution(1,0,0)
print(t.randPoint())



# Your Solution object will be instantiated and called as such:
# obj = Solution(radius, x_center, y_center)
# param_1 = obj.randPoint()