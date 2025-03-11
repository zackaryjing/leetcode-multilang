import bisect
from collections import defaultdict
from typing import *


class Solution:
    def maximumBeauty(self, items: List[List[int]], queries: List[int]) -> List[int]:
        n = len(items)
        items.sort()
        max_num = 0
        new_items = []
        last = -1
        for i in range(n):
            k, v = items[i]
            max_num = max([max_num, v])
            if k == last:
                new_items[-1] = [k, max_num]
            else:
                new_items.append([k, max_num])

        m = len(queries)

        ans = [0 for _ in range(m)]
        for i in range(m):
            local = bisect.bisect_right(new_items, queries[i], key=lambda x: x[0])  # 找到第一个 `jiage[i] > x` 的索引
            ans[i] = new_items[local - 1][1] if local > 0 else 0
        return ans


class Solution2:
    def maximumBeauty(self, items: List[List[int]], queries: List[int]) -> List[int]:
        print(queries)
        items.sort(key=lambda x: x[1])
        table: defaultdict = defaultdict(int)
        max_num = 0
        for k, v in items:
            table[k] = max([max_num, v, table[k]])
            max_num = table[k]
        print(items)
        pb = sorted([[p, b] for p, b in table.items()])
        print(pb)
        ans = []
        m = len(queries)

        n = len(pb)

        def double_search(num: int):
            left = 0
            right = n - 1
            while left != right:
                mid = (left + right + 1) // 2
                if pb[mid][0] <= num:
                    # print(mid + 1, n)
                    left = mid
                    if (mid + 1) > (n - 1) or pb[mid + 1][0] > num:
                        break
                else:
                    right = mid - 1
                # print(left, mid, right)
            return 0 if pb[left][0] > num else pb[left][1]

        for i in range(m):
            # print("q:", queries[i])
            ans.append(double_search(queries[i]))
        return ans


def main():
    test = Solution()
    print(test.maximumBeauty(
        [[193, 732], [781, 962], [864, 954], [749, 627], [136, 746], [478, 548], [640, 908], [210, 799], [567, 715],
         [914, 388], [487, 853], [533, 554], [247, 919], [958, 150], [193, 523], [176, 656], [395, 469], [763, 821],
         [542, 946], [701, 676]],
        [885, 1445, 1580, 1309, 205, 1788, 1214, 1404, 572, 1170, 989, 265, 153, 151, 1479, 1180, 875, 276, 1584]))
    # print(test.maximumBeauty([[1, 2], [3, 2], [2, 4], [5, 6], [3, 5]], [1, 2, 3, 4, 5, 6]))


if __name__ == "__main__":
    main()
