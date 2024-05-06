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

class Solution:
    def ambiguousCoordinates(self, s: str) -> List[str]:
        # "asdf 4"
        s.replace("(","")
        s.replace(")","")
        n = len(s)
        def checkvalid(num:str):
            if (num.startswith("0") and not num.startswith("0.")) or num.endswith("0") or num.endswith("."):
                return False
            return True
        ans = []
        for i in range(n-1):
            first = s[:i+1]
            second = s[i+1:]
            for t in range(1,len(first)):
                for k in range(1,len(second)):
                    temp = ""
                    befordot1 = first[:t + 1]
                    afterdot1 = first[t + 1:]
                    if checkvalid(befordot1+"."+afterdot1):
                        temp += "("+befordot1+"."+afterdot1
                    else:
                        break
                    befordot2 = second[:k + 1]
                    afterdot2 = second[k + 1:]
                    if checkvalid(befordot2+"."+afterdot2):
                        temp += ","+befordot2+"."+afterdot2+")"
                    else:
                        break
                    ans.append(temp)
        return ans
    
t = Solution()
print(t.ambiguousCoordinates("(12345)"))
print(t.ambiguousCoordinates("(00011)"))

    
        