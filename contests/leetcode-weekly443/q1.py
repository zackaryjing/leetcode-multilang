# problem: 
from typing import *


class Solution:
    def minCosts(self, cost: List[int]) -> List[int]:
        min_num = cost[0]
        for i in range(len(cost)):
            min_num = min(cost[i], min_num)
            cost[i] = min_num
        return cost


def main():
    test = Solution()
    print(test.minCosts([5,3,4,1,3,2]))


if __name__ == "__main__":
    main()
