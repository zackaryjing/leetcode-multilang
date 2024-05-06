import random
from typing import *
from functools import cmp_to_key
class Solution2:
    def __init__(self, nums: List[int]):
        self.value = nums
        self.copy = nums[:]
        self.n = len(nums)
        
    def reset(self) -> List[int]:
        self.value = self.copy[:]
        return self.value

    def shuffle(self) -> List[int]:
        # self.value.sort(key=cmp_to_key(lambda x,y:random.choice([-1,1])))
        for i in range(self.n // 2):
            first = random.randint(0, self.n - 1)
            second = random.randint(0, self.n - 1)
            self.value[first],self.value[second] = self.value[second],self.value[first]
        # print("-"*40,"begin")
        # print(self.value)
        # print(self.copy)
        # print("-"*40)
        return self.value

class Solution:

    def __init__(self, nums: List[int]):
        self.value = nums
        self.origin = nums.copy()
        self.n = len(nums)

    def reset(self) -> List[int]:
        self.nums = self.origin.copy()
        return self.nums
    
    def shuffle(self) -> List[int]:
        shuffed = [0] * self.n
        for i in range(self.n):
            j = random.randrange(len(self.value))
            shuffed[i] = self.value.pop(j)
        self.value = shuffed
        return self.value


        
test = Solution([1,2,3])
a = b = c = d = e = f = 0
for i in range(1000000):
    test.shuffle()
    if test.value == [1,2,3]:
        a += 1
    if test.value == [2,3,1]:
        b += 1
    if test.value == [2,1,3]:
        c += 1
    if test.value == [1,3,2]:
        d += 1
    if test.value == [3,1,2]:
        e += 1
    if test.value == [3,2,1]:
        f += 1
print(a,b,c,d,e,f)
# for i in range(100):
#     print(random.randint(0,1))


# Your Solution object will be instantiated and called as such:
# obj = Solution(nums)
# param_1 = obj.reset()
# param_2 = obj.shuffle()