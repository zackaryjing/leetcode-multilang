class Solution:
    def validSquare(self, p1: list[int], p2: list[int], p3: list[int], p4: list[int]) -> bool:
        if (p1 == p2) or (p3 == p4) or(p3 == p1) or(p1 == p4) or(p3 == p2) or(p2 == p4):
            return False
        s1 = (p1[0] - p2[0])**2 + (p1[1] - p2[1])**2
        s2 = (p1[0] - p3[0])**2 + (p1[1] - p3[1])**2
        s3 = (p1[0] - p4[0])**2 + (p1[1] - p4[1])**2
        s4 = (p2[0] - p4[0])**2 + (p2[1] - p4[1])**2
        s5 = (p2[0] - p3[0])**2 + (p2[1] - p3[1])**2
        s6 = (p3[0] - p4[0])**2 + (p3[1] - p4[1])**2
        a = {s1,s2,s3,s4,s5,s6}
        if len(a) != 2:
            return False
        else:
            if 2 * min(a) != max(a):
                return False
        return True

t = Solution()
print(t.validSquare([0,0],[1,1],[1,0],[0,1]))
print(t.validSquare([0,0],[1,1],[1,0],[0,12]))
print(t.validSquare([1,0],[-1,0],[0,1],[0,-1]))
print(t.validSquare([0,0],[1,1],[1,0],[1,1]))
print(t.validSquare([0,1],[1,2],[0,2],[0,0]))