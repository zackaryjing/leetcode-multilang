from typing import *
from collections import defaultdict
class Solution:
    def isRectangleCover(self, rectangles: List[List[int]]) -> bool:
        each_point = defaultdict(int)
        left_bottom = [float('inf'),float('inf')]
        right_top = [-float('inf'),-float('inf')]
        square = 0
        for x,y,a,b in rectangles:
            square += (a - x) * (b - y)
            if x <= left_bottom[0] and y <= left_bottom[1]:
                left_bottom = [x,y]
            if a >= right_top[0] and b >= right_top[1]:
                right_top = [a,b]
            each_point[(x, y)] += 1
            each_point[(a, b)] += 1
            each_point[(a, y)] += 1
            each_point[(x, b)] += 1
        # print(each_point)
        # print(right_top,left_bottom)
        if square != (right_top[0] - left_bottom[0]) * (right_top[1] - left_bottom[1]):
            # print("?")
            return False
        if each_point[(left_bottom[0], left_bottom[1])] != 1 or \
                each_point[(left_bottom[0], right_top[1])] != 1 or \
                each_point[(right_top[0], left_bottom[1])] != 1 or \
                each_point[(right_top[0], right_top[1])] != 1:
              return False
        
        for key,values in each_point.items():
            if values != 2 and values != 4:
                if not (values == 1 and (
                    key == (left_bottom[0], left_bottom[1]) or
                    key == (left_bottom[0], right_top[1]) or
                    key == (right_top[0], left_bottom[1]) or
                        key == (right_top[0], right_top[1]))):
                    # print(values,key)
                    return False
        return True
    
t = Solution()
print(t.isRectangleCover([[0,0,1,1],[0,0,1,1],[1,1,2,2],[1,1,2,2]]))
print(t.isRectangleCover([[1,1,3,3],[3,1,4,2],[3,2,4,4],[1,3,2,4],[2,3,3,4]]))
print(t.isRectangleCover([[0,0,4,1],[7,0,8,2],[6,2,8,3],[5,1,6,3],[4,0,5,1],[6,0,7,2],[4,2,5,3],[2,1,4,3],[0,1,2,2],[0,2,2,3],[4,1,5,2],[5,0,6,1]]))






