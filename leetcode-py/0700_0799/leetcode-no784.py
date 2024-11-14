from typing import *
from collections import deque
class Solution3:
    def letterCasePermutation(self, s: str) -> List[str]:
        ans = deque([""])
        length = 1
        for i in s:
            print('-='*20)
            if 'a' <= i <= 'z':
                for k in range(0,length):
                    ans.extend([(a := ans.popleft()) + i,a + str.upper(i)])
                    print(a,length)
                    print(ans)
            elif 'A' <= i <= 'Z':
                for k in range(0,length):
                    ans.extend([(a := ans.popleft()) + i,a + str.lower(i)])
                    print(a,length)
                    print(ans)
            else:
                for k in range(0,length):
                    ans.extend([(a := ans.popleft()) + i,a + str.lower(i)])

            length *= 2
        return ans

class Solution:
    def letterCasePermutation(self, s: str) -> List[str]:
        length = 1
        ans = deque([""])
        for i in s:
            if 'a' <= i <= 'z':
                for k in range(length):
                    ans.extend([(tmp := ans.popleft()) + i,tmp + i.upper()])
                    # print(ans,k)
                length *= 2
            elif 'A' <= i <= 'Z':
                for k in range(length):
                    ans.extend([(tmp := ans.popleft()) + i,tmp + i.lower()])
                    # print(ans,k)
                length *= 2
            else:
                for k in range(length):
                    ans.append(ans.popleft() + i)
                    # print(ans,k)
        return list(ans)


t = Solution()
print(t.letterCasePermutation("a1kd2i"))
