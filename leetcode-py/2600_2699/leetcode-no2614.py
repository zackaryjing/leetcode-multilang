# problem: prime-in-diagonal
import math
from functools import lru_cache
from typing import *


class Solution:
    @lru_cache
    def is_prime(self, num: int):
        k = math.ceil(math.sqrt(num))
        if num == 1:
            return False
        if num == 2:
            return True
        for i in range(2,k + 1):
            if num % i == 0:
                return False
        return True


    def diagonalPrime(self, nums: List[List[int]]) -> int:
        n = len(nums)
        ans = 0
        for i in range(n):
            if self.is_prime(nums[i][i]):
                ans = max(ans,nums[i][i])
            if self.is_prime(nums[i][n - i - 1]):
                ans = max(ans,nums[i][n - i - 1])
        return ans



def main():
    test = Solution()
    print(test.diagonalPrime([[1,2,3],[5,6,7],[9,10,11]]))
    print(test.diagonalPrime([[1,2,3],[5,17,7],[9,11,10]]))
    print(test.is_prime(985))




if __name__ == "__main__":
    main()
