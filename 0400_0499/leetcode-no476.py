import math
class Solution2:
    def findComplement(self, num: int) -> int:
        s = bin(num)
        s = s.replace("0","x")
        s = s.replace("1","0")
        s = s.replace("x","1")
        return int(s[2:],2)
   
MASK = 2 ** 31 - 1
class Solution:
    def findComplement(self, num: int) -> int:
        n = int(math.log2(num))
        return num ^ (2 ** (n + 1) - 1)
    
t = Solution()
print(t.findComplement(5))