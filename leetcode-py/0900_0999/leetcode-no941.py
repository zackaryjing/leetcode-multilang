# problem: https://leetcode.cn/problems/valid-mountain-array/description/
from typing import *

class Solution:
    def validMountainArray(self, arr: List[int]) -> bool:
        n = len(arr)
        last = arr[0]
        first_stage = False
        second_stage = False
        for i in range(1,n):
            if arr[i] > last:
                if second_stage:
                    return False
                first_stage = True
            elif arr[i] < last:
                second_stage = True
            else:
                return False
            last = arr[i]
        
        return True if second_stage and first_stage else False
                


def main():
    test = Solution()
    print(test.validMountainArray([0,2,3,4,5,2,1,0]))
    print(test.validMountainArray([2,1]))
    print(test.validMountainArray([0,2,3,4,5,2,1,0]))



if __name__ == "__main__":
    main()
