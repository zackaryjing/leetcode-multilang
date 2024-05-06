# The rand7() API is already defined for you.
# def rand7():
# @return a random integer in the range 1 to 7
from collections import defaultdict
import random
import pprint
def rand7()-> float:
    return random.randint(1,7)
class Solution:
    def rand10(self):
        while not (first := rand7()) < 7:
            pass
        while not (second := rand7()) < 6:
            pass
        return second + (5 if first % 2 else 0)

def show(alist):
    data = defaultdict(int)
    for k in alist:
        data[k] += 1
    h = list(data.items())
    h.sort()
    for i,j in h:
        print("{0:} counts {1:}".format(i,j))
t = Solution()
test = [t.rand10() for _ in range(10000)]
show(test)