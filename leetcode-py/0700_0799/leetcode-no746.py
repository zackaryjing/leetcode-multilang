from typing import *


class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        cost_l, cost_r = 0, 0
        for i in range(2, n + 1):
            cost_l, cost_r = cost_r, min([cost[i - 2] + cost_l, cost[i - 1] + cost_r])
        return cost_r


class Solution2:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        dp = [0 for _ in range(n + 1)]
        for i in range(2, n + 1):
            dp[i] = min([cost[i - 2] + dp[i - 2], cost[i - 1] + dp[i - 1]])
        return dp[n]


def main():
    test = Solution()
    print(test.minCostClimbingStairs([10, 15, 20]))
    print(test.minCostClimbingStairs([1, 100, 1, 1, 1, 100, 1, 1, 100, 1]))


if __name__ == "__main__":
    main()
