class Solution:
    def computeArea(self, ax1: int, ay1: int, ax2: int, ay2: int, bx1: int, by1: int, bx2: int, by2: int) -> int:
        def getcmn(first, second):
            if first[2] < second[0] or first[3] < second[1] or first[1] > second[3] or first[0] > second[2]:
                return 0
            leftbottomy = max(first[0], second[0])
            leftbottomx = max(first[1], second[1])
            righttopy = min(first[2], second[2])
            righttopx = min(first[3], second[3])
            return (righttopy - leftbottomy) * (righttopx - leftbottomx)
        return -getcmn([ax1,ay1,ax2,ay2],[bx1,by1,bx2,by2]) + (ay2 - ay1) * (ax2 - ax1) +(by2 - by1) * (bx2 - bx1)

t = Solution()
print(t.computeArea(ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2))


