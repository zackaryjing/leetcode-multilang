from typing import *


class Solution:
    def furthestDistanceFromOrigin(self, moves: str) -> int:
        left = moves.count("L")
        right = moves.count("R")
        both = moves.count("_")
        return max(left - right, right - left) + both


class Solution2:
    def furthestDistanceFromOrigin(self, moves: str) -> int:
        cur_left = 0
        cur_right = 0
        for m in moves:
            if m == 'L':
                cur_left += 1
                cur_right -= 1
            elif m == 'R':
                cur_right += 1
                cur_left -= 1
            else:
                cur_left += 1
                cur_right += 1
        return max(cur_left, cur_right)


def main():
    test = Solution()
    print(test.furthestDistanceFromOrigin("L_RL__R"))
    print(test.furthestDistanceFromOrigin("_R__LL_"))
    print(test.furthestDistanceFromOrigin("_______"))


if __name__ == "__main__":
    main()
