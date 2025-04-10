# problem: https://leetcode.cn/problems/count-the-number-of-powerful-integers/?envType=daily-question&envId=2025-04-10
from typing import *


class Solution:
    def numberOfPowerfulInt(self, start: int, finish: int, limit: int, s: str) -> int:
        n = len(s)

        def powerfulInt(top: str) -> int:
            m = len(top)
            if m <= n:
                return 1 if int(top) >= int(s) else 0
            res = 0
            length = m - n
            for i in range(length):
                if int(top[i]) > limit:
                    res += (limit + 1) ** (length - i)
                    return res
                else:
                    res += (int(top[i])) * (limit + 1) ** max((length - i - 1), 0)

            if int(top[length - 1]) <= limit:
                res += 1 if (int(top) % (10 ** n)) >= int(s) else 0
            return res
        return powerfulInt(str(finish)) - powerfulInt(str(start - 1))


def main():
    test = Solution()
    print(test.numberOfPowerfulInt(1114,1864854501 , 7, "26"))
    print(test.numberOfPowerfulInt(1, 6000, 4, "124"))
    print(test.numberOfPowerfulInt(20, 1159, 5, "20"))
    print(test.numberOfPowerfulInt(1, 971, 9, "72"))
    print(test.numberOfPowerfulInt(1, 971, 9, "17"))
    print(test.numberOfPowerfulInt(15, 215, 6, "10"))


if __name__ == "__main__":
    main()
