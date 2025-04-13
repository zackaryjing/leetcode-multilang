# problem:
from typing import *

class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        return sum(nums) - (sum(nums) // k) * k

def main():
    test = Solution()
    print(test.minOperations())
    

if __name__ == "__main__":
    main()

#
# Created by: ASUS At: 2025/4/12 21:30 
#