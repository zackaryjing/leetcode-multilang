from typing import *
from itertools import product
class Solution:
    def ambiguousCoordinates(self, s: str) -> List[str]:
        s = s.removeprefix("(")
        s = s.removesuffix(")")
        # print(s)
        n = len(s)
        ans = []
        def checkvalid(numfront:str,numback:str):
            if (numfront != "0" and numfront.startswith("0") and not numfront.startswith("0.")):
                return False
            if numback.endswith("0"):
                return False
            # print(num)
            return True
        # print(checkvalid("0"))
        for comma in range(1,n):
            valid = True
            first = s[:comma]
            second = s[comma:]
            # print(first,second,"------")
            firstok = []
            secondok = []
            if checkvalid(first,""):
                firstok.append(first)
            if checkvalid(second,""):
                secondok.append(second)
            for dot in range(1,len(first)):
                if checkvalid(first[:dot],first[dot:]):
                    firstok.append(first[:dot]+"."+first[dot:])
            for dot in range(1,len(second)):
                if checkvalid(second[:dot],second[dot:]):
                    secondok.append(second[:dot] + "." + second[dot:])
            for k,j in product(firstok,secondok):
                ans.append("("+k+", "+j+")")
        return ans
    
t = Solution()
print(t.ambiguousCoordinates("(12345)"))
print(t.ambiguousCoordinates("(00011)"))

    
        