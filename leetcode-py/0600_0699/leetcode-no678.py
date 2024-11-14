from typing import *
class Solution:
    def checkValidString(self, s: str) -> bool:
        leftstack = []
        astrastack = []
        n = len(s)
        for i in range(n):
            if s[i] == "(":
                leftstack.append(i)
            elif s[i] == "*":
                astrastack.append(i)
            else:
                if leftstack:
                    leftstack.pop()
                elif astrastack:
                    astrastack.pop()
                else:
                    return False
        if len(leftstack) > len(astrastack):
            return False
        while leftstack:
            if leftstack.pop() > astrastack.pop():
                return False
        return True




t = Solution()
print(t.checkValidString("()"))
print(t.checkValidString("(*)"))
print(t.checkValidString("**(()"))
print(t.checkValidString("((()*)"))
print(t.checkValidString("()()()((((()((()(()())(()))(())))((()((()())*(((())()))(()((())(((((((())()*)())((())*))))*)())()))"))

