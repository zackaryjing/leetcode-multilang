# problem: https://leetcode.cn/contest/biweekly-contest-182/problems/score-validator/
from typing import *

class Solution:
    def scoreValidator(self, events: list[str]) -> list[int]:
        res = 0
        counter = 0
        for action in events:
            if action in "0123456":
                res += int(action);
            elif action == "W":
                counter += 1
            elif action == "WD" or action == "NB":
                res += 1
            if counter == 10:
                break
        return [res,counter]




def main():
    test = Solution()
    print(test.scoreValidator(["1","4","W","6","WD"]))
    print(test.scoreValidator(["WD","NB","0","4","4"]))
    print(test.scoreValidator(["W","W","W","W","W","W","W","W","W","W","W"]))


if __name__ == "__main__":
    main()

#
# Created by: jing At: 2026-05-09 22:25:52
#