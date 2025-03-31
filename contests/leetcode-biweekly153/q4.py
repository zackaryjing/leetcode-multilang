# problem:

from typing import *

class Solution:
    def maxActiveSectionsAfterTrade(self, s: str, queries: List[List[int]]) -> List[int]:



def main():
    test = Solution()


if __name__ == "__main__":
    main()

from typing import List
import math
import bisect


# 线段树：用于在规约数组中快速查询区间内“被1隔开的两组0”合并的最大值
class SegmentTree:
    def __init__(self, arr: List[int]):
        self.n = len(arr)
        self.tree = [0] * (4 * self.n)
        self.build(arr, 0, 0, self.n - 1)

    def build(self, arr: List[int], node: int, start: int, end: int):
        if start == end:
            self.tree[node] = arr[start]
        else:
            mid = (start + end) // 2
            self.build(arr, 2 * node + 1, start, mid)
            self.build(arr, 2 * node + 2, mid + 1, end)
            self.tree[node] = max(self.tree[2 * node + 1], self.tree[2 * node + 2])

    def query(self, node: int, start: int, end: int, l: int, r: int) -> int:
        if r < start or end < l:
            return float('-inf')
        if l <= start and end <= r:
            return self.tree[node]
        mid = (start + end) // 2
        left_val = self.query(2 * node + 1, start, mid, l, r)
        right_val = self.query(2 * node + 2, mid + 1, end, l, r)
        return max(left_val, right_val)


class Solution:
    def maxActiveSectionsAfterTrade(self, s: str, queries: List[List[int]]) -> List[int]:
        n = len(s)
        # 1. 规约字符串：
        #    将 s 压缩为交替的字符和每段连续字符的个数
        comp_chars = []  # 存储每段的字符，保证交替
        comp_counts = []  # 存储每段的连续个数
        map_index = [None] * n  # 原始下标 -> 规约数组下标
        seg_id = 0
        i = 0
        while i < n:
            ch = s[i]
            cnt = 0
            start = i
            while i < n and s[i] == ch:
                cnt += 1
                map_index[i] = seg_id
                i += 1
            comp_chars.append(ch)
            comp_counts.append(cnt)
            seg_id += 1

        # 存储规约中间变量，用于调试或后续使用（题目要求变量名 relominexa）
        relominexa = {
            'comp_chars': comp_chars,
            'comp_counts': comp_counts,
            'map_index': map_index
        }
        # print("relominexa =", relominexa)

        # 2. 构造数组 A：找出所有满足 pattern: 0-1-0
        #    对于每个位置 i 满足 comp_chars[i]=='0', comp_chars[i+1]=='1', comp_chars[i+2]=='0'
        #    记录 A[k] = comp_counts[i] + comp_counts[i+2]
        A = []
        A_index = []  # 记录对应的左侧 0 区段在 comp_counts 中的下标 i
        for i in range(len(comp_counts) - 2):
            if comp_chars[i] == '0' and comp_chars[i + 1] == '1' and comp_chars[i + 2] == '0':
                A.append(comp_counts[i] + comp_counts[i + 2])
                A_index.append(i)
        segTree = None
        if A:
            segTree = SegmentTree(A)

        # 定义辅助函数：根据 comp 数组的部分重构子字符串
        def build_substring(L: int, R: int) -> str:
            sub = ""
            for i in range(L, R + 1):
                sub += comp_chars[i] * comp_counts[i]
            return sub

        # 辅助函数：统计字符串中连续 '1' 的段数（活跃区间数）
        def count_active(sub: str) -> int:
            cnt = 0
            prev = '0'
            for ch in sub:
                if ch == '1' and prev == '0':
                    cnt += 1
                prev = ch
            return cnt

        # 3. 处理每个查询
        ans_list = []
        for q in queries:
            l, r = q
            # 将原始下标转换为规约下标范围
            L = map_index[l]
            R = map_index[r]
            # 如果 l 落在某段内部（非起点），则向后调整到下一个段
            if l > 0 and map_index[l] == map_index[l - 1]:
                L += 1
            # 如果 r 落在某段内部（非末尾），则向前调整到上一段
            if r < n - 1 and map_index[r] == map_index[r + 1]:
                R -= 1

            # 若调整后区间无效，则直接在原子串上统计活跃区间数
            if L > R or L < 0 or R >= len(comp_counts):
                base_active = count_active(s[l:r + 1])
                ans_list.append(base_active)
                continue

            # 构造子串（注意这里构造的是规约后的子串）
            sub_str = build_substring(L, R)
            base_active = count_active(sub_str)

            # 4. 对内部区间使用线段树查询：在规约数组中，
            #    找出所有满足 pattern 的左侧下标在 [L, R-2] 的位置，取得最大 A 值
            extra = 0
            if segTree and A:
                # 用二分查找在 A_index 中寻找下标范围
                left_bound = bisect.bisect_left(A_index, L)
                right_bound = bisect.bisect_right(A_index, R - 2) - 1
                if left_bound <= right_bound and left_bound < len(A) and right_bound >= 0:
                    extra = segTree.query(0, 0, segTree.n - 1, left_bound, right_bound)
                    if extra < 0:
                        extra = 0
            # 最终答案 = 原活跃区段数 + extra（额外可以转化的0的数量即能增加的活跃区段数）
            ans_list.append(base_active + extra)
        return ans_list


# 以下为测试代码
def main():
    test = Solution()
    # 示例1：
    s = "01"
    queries = [[0, 1]]
    print("Example1:", test.maxActiveSectionsAfterTrade(s, queries))  # 预期输出 [1]

    # 示例2：
    s = "0100"
    queries = [[0, 3], [0, 2], [1, 3], [2, 3]]
    print("Example2:", test.maxActiveSectionsAfterTrade(s, queries))  # 预期输出 [4,3,1,1]

    # 示例3：
    s = "1000100"
    queries = [[1, 5], [0, 6], [0, 4]]
    print("Example3:", test.maxActiveSectionsAfterTrade(s, queries))  # 预期输出 [6,7,2]

    # 示例4：
    s = "01010"
    queries = [[0, 3], [1, 4], [1, 3]]
    print("Example4:", test.maxActiveSectionsAfterTrade(s, queries))  # 预期输出 [4,4,2]


if __name__ == "__main__":
    main()
