from typing import *
class Solution:
    def buyChoco(self, prices: List[int], money: int) -> int:
        prices.sort()
        if prices[0] + prices[1] > money:
            return money
        else:
            return money - (prices[0] + prices[1])
        
t = Solution()
print(t.buyChoco([1,2,2],3))
print(t.buyChoco([3,2,3],3))
