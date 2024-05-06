from math import factorial
from math import ceil





class Solution3:
    def getPermutation(self, n: int, k: int) -> str:
        avaliable = list(range(n))
        ans = ""
        while n > 1:
            ans += str(avaliable[ceil(k / factorial(n - 1)) - 1])




class Solution2:
    def getPermutation(self, n: int, k: int) -> str:
        avaliable = list(range(1,n+1))
        # print(avaliable)
        ans = ""
        # if k == 1:
        #     return "".join(map(str,avaliable))
        while n > 0:
            print(k)
            ans += str(tmp := avaliable[ceil(k / factorial(n-1))-1])
            avaliable.remove(tmp)
            k = h if (h := (k % factorial(n-1))) != 0 else k
            n -= 1
            print(ans, avaliable,k)
        ans += "".join(map(str,avaliable))
        return ans


class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        k -= 1
        avaliable = list(range(1,n+1))
        ans = ""
        while n > 1:
            n -= 1
            ans += str(avaliable[(tmp := (k // factorial(n)))])
            del avaliable[tmp]
            k %= factorial(n)
        ans += "".join(map(str,avaliable))
        return ans

t = Solution()
print(t.getPermutation(1,1))
print(t.getPermutation(3,3))
print(t.getPermutation(3,2))
print(t.getPermutation(4,9))
print(t.getPermutation(3,1))




