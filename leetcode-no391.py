from typing import *
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
print(t.ambiguousCoordinates("(123)"))




