from itertools import combinations
from copy import deepcopy
class Solution2:
    def fieldOfGreatestBlessing(self, forceField: list[list[int]]) -> int:
        fields = [(i-k/2,j-k/2,i+k/2,j+k/2) for i,j,k in forceField]
        def getcmn(first,second):
            if first[2] < second[0]:
                return ()
            if first[3] < second[1]:
                return ()
            if first[1] > second[3]:
                return ()
            if first[0] > second[2]:
                return ()
            leftbottomy = max(first[0],second[0])
            leftbottomx = max(first[1],second[1])
            righttopy = min(first[2],second[2])
            righttopx = min(first[3],second[3])
            return (leftbottomy,leftbottomx,righttopy,righttopx)
        # print(fields,"***")
        times = 0
        currentmutil = set()
        while len(currentmutil) != 0 or times == 0:
            if times == 0:
                topro = fields
            else:
                topro = currentmutil
            currentmutil = set()
            for first,second in combinations(topro,2):
                temp = getcmn(first,second)
                if temp != ():
                    currentmutil.add(temp)
            times += 1
            # print(times,currentmutil)
        return times
            # n = len(topro)
            # for i in range(n):
            #     for j in range(i+1,n):
            #         print(i,j)
            #         print(fields[i],fields[j])
            #         print(getcmn(fields[i],fields[j]))

from itertools import combinations
from functools import cache
from copy import deepcopy
class Solution5:
    def fieldOfGreatestBlessing(self, forceField: list[list[int]]) -> int:
        fields = [(i-k/2,j-k/2,i+k/2,j+k/2) for i,j,k in forceField]
        @cache
        def getcmn(first,second):
            if first[2] < second[0]:
                return ()
            if first[3] < second[1]:
                return ()
            if first[1] > second[3]:
                return ()
            if first[0] > second[2]:
                return ()
            return (max(first[0],second[0]),max(first[1],second[1]),min(first[2],second[2]),min(first[3],second[3]))

        times = 0
        while times == 0 or len(currentmutil) != 0:
            if times == 0:
                topro = fields
            else:
                topro = currentmutil
            currentmutil = set()
            for combin in combinations(topro,2):
                temp = getcmn(*combin)
                if temp != ():
                    currentmutil.add(temp)
            times += 1
        return times

from itertools import combinations
from functools import cache
class Solution3:
    def fieldOfGreatestBlessing(self, forceField: list[list[int]]) -> int:
        fields = [(i-k/2,j-k/2,i+k/2,j+k/2) for i,j,k in forceField]
        def getcmn(first,second):
            if first[2] < second[0]:
                return ()
            if first[3] < second[1]:
                return ()
            if first[1] > second[3]:
                return ()
            if first[0] > second[2]:
                return ()
            return (max(first[0],second[0]),max(first[1],second[1]),min(first[2],second[2]),min(first[3],second[3]))

        times = 0
        currentmutil = set()
        while times == 0 or len(currentmutil) != 0:
            if times == 0:
                topro = fields
            else:
                topro = currentmutil
            currentmutil = set()
            for combin in combinations(topro,2):
                temp = getcmn(*combin)
                if temp != ():
                    currentmutil.add(temp)
            times += 1
        return times
# print(t.fieldOfGreatestBlessing([[4,4,6],[7,5,3],[1,6,2],[5,6,3]]))

class Solution4:
    def fieldOfGreatestBlessing(self, forceField: list[list[int]]) -> int:
        fields = [(i-k/2,j-k/2,i+k/2,j+k/2) for i,j,k in forceField]
        # print(fields)
        def getcmn(first, second):
            if first[2] < second[0] or first[3] < second[1] or first[1] > second[3] or first[0] > second[2]:
                return ()
            return (
            max(first[0], second[0]), max(first[1], second[1]), min(first[2], second[2]), min(first[3], second[3]))

        currentmutil = set()
        times = 0

        while times == 0 or len(currentmutil) != 0:
            if times == 0:
                topro = fields
            else:
                topro = list(currentmutil)
                currentmutil.clear()

            found_overlap = False

            for i in range(len(topro)):
                for j in range(i + 1, len(topro)):
                    temp = getcmn(topro[i], topro[j])
                    if temp != ():
                        found_overlap = True
                        currentmutil.add(temp)

            if not found_overlap:
                return times + 1

            times += 1

        return times


from typing import List

class Solution:
    def maxForce(self, forceField: List[List[int]]) -> int:
        # 将覆盖区域转换为四元组 (x1, y1, x2, y2) 并加入集合 S
        S = set()
        for f in forceField:
            x, y, s = f
            S.add((x - s // 2, y - s // 2, x + s // 2, y + s // 2))

        # 合并集合 S 中所有区域
        while True:
            merged = False
            for r1 in S:
                for r2 in S:
                    if r1 == r2:
                        continue
                    if self.intersect(r1, r2):
                        S.remove(r1)
                        S.remove(r2)
                        S.add(self.merge(r1, r2))
                        merged = True
                        break
                if merged:
                    break
            if not merged:
                break

        # 枚举每个点，统计其力场强度
        res = 0
        for x, y, _ in forceField:
            cnt = 0
            for r in S:
                if r[0] <= x <= r[2] and r[1] <= y <= r[3]:
                    cnt += 1
            res = max(res, cnt)

        return res

    # 判断两个区域是否有交集
    def intersect(self, r1, r2):
        return not (r1[2] < r2[0] or r1[3] < r2[1] or r2[2] < r1[0] or r2[3] < r1[1])

    # 合并两个区域
    def merge(self, r1, r2):
        return (min(r1[0], r2[0]), min(r1[1], r2[1]), max(r1[2], r2[2]), max(r1[3], r2[3]))

# 测试
forceField = [[0,0,1],[1,0,1]]
print(Solution().maxForce(forceField)) # 2

forceField = [[4,4,6],[7,5,3],[1,6,2],[5,6,3]]
print(Solution().maxForce(forceField)) # 3

# t = Solution2()
# print(t.fieldOfGreatestBlessing([[0,0,1],[1,0,1]]))
# print(t.fieldOfGreatestBlessing([[0,0,1],[1,0,1]]))
# print(t.fieldOfGreatestBlessing([[4,4,6],[7,5,3],[1,6,2],[5,6,3],[3,5,4]]))
# print(t.fieldOfGreatestBlessing([[4,4,6],[7,5,3],[1,6,2],[5,6,3],[3,5,4],[5,5,1]]))
# print(t.fieldOfGreatestBlessing([[564,381,960],[427,301,536],[759,976,146],[949,483,364],[146,94,474],[606,974,647],[433,190,653],[306,816,89],[653,112,495],[364,284,774],[87,115,209],[255,572,302],[456,621,2],[648,705,851],[379,158,716],[653,815,460],[972,720,634],[542,457,474],[60,951,8],[386,409,224],[419,190,306],[9,787,118],[428,432,788],[986,443,645],[746,179,309],[923,254,559],[329,983,624],[452,465,160],[209,349,435],[564,381,960],[427,301,536],[759,976,146],[949,483,364],[146,94,474],[606,974,647],[433,190,653],[306,816,89],[653,112,495],[364,284,774],[87,115,209],[255,572,302],[456,621,2],[648,705,851],[379,158,716],[653,815,460],[972,720,634],[542,457,474],[60,951,8],[386,409,224],[419,190,306],[9,787,118],[428,432,788],[986,443,645],[746,179,309],[923,254,559],[329,983,624],[452,465,160],[209,349,435]]))
# # print(t.fieldOfGreatestBlessing([[0,0,1],[0.9,1.1,1]]))
