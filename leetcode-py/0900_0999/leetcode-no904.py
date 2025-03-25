# problem: fruit-into-baskets
from typing import *


class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        cur_len = 0
        last = -1
        ans = 1
        allowed = [-1, -1]
        length = 0
        for fruit in fruits:
            if fruit not in allowed:
                length = cur_len + 1
                allowed = [last, fruit]
            else:
                length += 1
            if fruit != last:
                cur_len = 1
            else:
                cur_len += 1
            ans = max(length, ans)
            last = fruit
        return ans


def main():
    test = Solution()
    print(test.totalFruit([1,2,3,2,2]))
    print(test.totalFruit([3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4]))
    print(test.totalFruit([0]))


if __name__ == "__main__":
    main()
