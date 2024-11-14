from typing import *
import numpy as np
from pprint import pprint


class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        if amount == 0:
            return 1
        n = len(coins)
        dp = [[0] * (amount + 1) for _ in range(n + 1)]
        for i in range(1, n + 1):
            coin = coins[i - 1]
            for j in range(amount + 1):
                if coin == j:
                    dp[i][j] = dp[i - 1][j] + 1
                elif j > coin:
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coin]
                else:
                    dp[i][j] = dp[i - 1][j]
        
        # pprint(dp)
        return dp[n][amount]


test = Solution()
print(test.change(5, [1, 2, 5]))
