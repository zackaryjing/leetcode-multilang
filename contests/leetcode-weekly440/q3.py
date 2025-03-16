import time
from typing import *


class SegmentTree:
    def __init__(self, a: List[int]):
        n = len(a)
        self.max = [0] * (2 << (n - 1).bit_length())
        self.build(a, 1, 0, n - 1)

    def maintain(self, o: int):
        self.max[o] = max(self.max[o * 2], self.max[o * 2 + 1])

    # 初始化线段树
    def build(self, a: List[int], o: int, l: int, r: int):
        if l == r:
            self.max[o] = a[l]
            return
        m = (l + r) // 2
        self.build(a, o * 2, l, m)
        self.build(a, o * 2 + 1, m + 1, r)
        self.maintain(o)

    # 找区间内的第一个 >= x 的数，并更新为 -1，返回这个数的下标
    def find_first_and_update(self, o: int, l: int, r: int, x: int) -> int:
        if self.max[o] < x:  # 区间没有 >= x 的数
            return -1
        if l == r:
            self.max[o] = -1  # 更新为 -1，表示不能放水果
            return l
        m = (l + r) // 2
        i = self.find_first_and_update(o * 2, l, m, x)  # 先递归左子树
        if i < 0:  # 左子树没找到
            i = self.find_first_and_update(o * 2 + 1, m + 1, r, x)  # 再递归右子树
        self.maintain(o)
        return i


class Solution:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        t = SegmentTree(baskets)
        n = len(baskets)
        ans = 0
        for x in fruits:
            if t.find_first_and_update(1, 0, n - 1, x) < 0:
                ans += 1
        return ans


class Solution2:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:

        t = SegmentTree(baskets)
        n = len(baskets)
        ans = 0
        for x in fruits:
            if t.find_first_and_update(1, 0, n - 1, x) < 0:
                ans += 1
        return ans


class Solution2:
    def numOfUnplacedFruits(self, fruits: List[int], baskets: List[int]) -> int:
        n = len(fruits)
        m = len(baskets)
        start_time = time.time()

        jump = [-1 for i in range(n)]
        pos = [-1 for i in range(n)]
        for i in range(n - 1, -1, -1):
            for j in range(i - 1, -1, -1):
                if fruits[i] >= fruits[j]:
                    jump[i] = j
                    break

        jump_time = time.time()  # 记录 jump 计算结束的时间
        print(f"生成 jump 数组耗时: {jump_time - start_time:.6f} 秒")

        min_not_use = 0

        used = [False for _ in range(m)]
        not_found = [True for _ in range(n)]

        search_start_time = time.time()  # 查找部分开始时间

        # print(jump)
        for i in range(n):
            start = max(min_not_use, pos[jump[i]] + 1)
            # print(min_not_use, pos[jump[i]] + 1)
            if start >= m:
                continue
            for j in range(start, m, 1):
                if not used[j] and baskets[j] >= fruits[i]:
                    used[j] = True
                    not_found[i] = False
                    pos[i] = j
                    break
            while min_not_use < m and used[min_not_use]:
                min_not_use += 1
            # print("nf:", not_found)
            # print("u:", used)
        # nf: [False, True, True, True, True, True]
        # u: [True, False, False, False, False, False]
        search_end_time = time.time()  # 查找部分结束时间
        print(f"查找篮子耗时: {search_end_time - search_start_time:.6f} 秒")
        return sum(not_found)


# nf: [False, True, True]
# u: [False, False, True]
# nf: [False, True, True]
# u: [False, False, True]
# nf: [False, True, False]
# u: [True, False, True]
# 1

def main():
    test = Solution()
    print(test.numOfUnplacedFruits([38, 65, 8], [27,10,47]))
    print(test.numOfUnplacedFruits([98,51,70,9,21], [21,52,3,30,16]))
    print(test.numOfUnplacedFruits([3, 6, 1, 2, 3, 8], [6, 4, 7, 3, 5, 12]))
    print(test.numOfUnplacedFruits([3, 6, 1], [6, 4, 7]))
    print(test.numOfUnplacedFruits([4, 2, 5], [3, 5, 4]))


if __name__ == "__main__":
    main()
