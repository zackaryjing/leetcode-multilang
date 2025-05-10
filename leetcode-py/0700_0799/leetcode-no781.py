# problem: https://leetcode.cn/problems/rabbits-in-forest/?envType=daily-question&envId=2025-04-20
from math import ceil
from typing import *
from collections import Counter


class Solution2:
    def numRabbits(self, answers: list[int]) -> int:
        answers.sort()
        current = -1
        times = 1
        total = answers.count(0)
        del answers[:total]
        for i in answers:
            # print(i)
            # print(times,"()")
            if i != current:
                times = 1
                current = i
                total += i + 1
            elif times > current + 1:
                # print("*")
                total += i + 1
                times = 1
            else:
                times += 1
        if times > current + 1:
            total += i + 1
        return total


class Solution3:
    def numRabbits(self, answers: list[int]) -> int:
        answers.sort()
        current = -1
        times = 1
        total = answers.count(0)
        del answers[:total]
        for i in answers:
            if i != current or times >= current + 1:
                # print(i, current, times)
                total += i + 1
                times = 1
                current = i
            else:
                times += 1
        if times > current + 1:
            total += i + 1
        return total


# 2025.4.20 reprogram
class Solution:
    def numRabbits(self, answers: list[int]) -> int:
        counter = Counter(answers)
        res = 0
        for i, times in counter.items():
            res += ceil(times / (i + 1)) * (i + 1)
        return res


# 5
# 11
# 5
# 6
# 13


def main():
    test = Solution3()
    print(test.numRabbits([1, 1, 2]))
    print(test.numRabbits([10, 10, 10]))
    print(test.numRabbits([1, 0, 1, 0, 0]))
    print(test.numRabbits([0, 0, 1, 1, 1]))
    print(test.numRabbits([2, 1, 2, 2, 2, 2, 2, 2, 1, 1]))


if __name__ == "__main__":
    main()

#
# Created At 2022.12.27 Updated on 2025.4.20 21:55
#
