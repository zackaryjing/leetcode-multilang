# problem: minimum-moves-to-equal-array-elements
from typing import *

class Solution:
    def minMoves(self, nums: List[int]) -> int:
        return sum(nums) - len(nums) * min(nums)

class Solution:
    def minMoves(self, nums: List[int]) -> int:
        min_element = min(nums)
        total = sum(nums)
        return total - len(nums) * min_element



def main():
    test = Solution()


if __name__ == "__main__":
    main()
