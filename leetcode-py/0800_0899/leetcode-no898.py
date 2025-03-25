# problem: bitwise-ors-of-subarrays/
from typing import *

class Solution3:
    def subarrayBitwiseORs(self, arr: List[int]) -> int:
        n :int = len(arr)
        ans = set()
        for i in range(n):
            cur = 0
            for j in range(i,-1,-1):
                cur |= arr[j]
                if j != i and arr[j] | cur == arr[j]:
                    break
                ans.add(cur)
                if cur > arr[j]:
                    arr[j] = cur
        return len(ans)


class Solution:
    def subarrayBitwiseORs(self, arr: List[int]) -> int:
        n :int = len(arr)
        ans = set()
        for i in range(n):
            cur = 0
            for j in range(i,-1,-1):
                cur |= arr[j]
                if i == j or cur > arr[j]:
                    arr[j] = cur
                    ans.add(cur)
                elif arr[j] | cur == arr[j]:
                    break
        return len(ans)


class Solution2:
    def subarrayBitwiseORs(self, arr: List[int]) -> int:
        n :int = len(arr)
        cur_sum = [-1] * n
        ans = set()
        for i in range(n):
            cur = 0
            for j in range(i,-1,-1):
                cur |= arr[j]
                if cur > cur_sum[j]:
                    cur_sum[j] = cur
                    ans.add(cur)
                elif cur_sum[j] | cur == cur_sum[j]:
                    break
        return len(ans)





def main():
    test = Solution()
    print(test.subarrayBitwiseORs([0]))
    print(test.subarrayBitwiseORs([1,1,2]))
    print(test.subarrayBitwiseORs([1,2,4]))



if __name__ == "__main__":
    main()
