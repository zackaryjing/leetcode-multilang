import cmath
class Solution:
    def complexNumberMultiply(self, num1: str, num2: str) -> str:
        a = num1.replace("i","j")
        b = num2.replace("i","j")
        a = eval(a)
        b = eval(b)
        return str(a*b).replace("j","i")

class Solution:
    def complexNumberMultiply(self, num1: str, num2: str) -> str:
        n1 = "0"
        n2 = ""
        k = 1
        for i in num1:
            if not i in "+-" and k and i != "i":
                n1 += i
            elif i != "i":
                n2 += i
                k = 0
        n1,n2 = int(n1),int(n2)
        m1 = "0"
        m2 = ""
        k = 1
        for i in num1:
            if not i in "+-" and k and i != "i":
                m1 += i
            elif i != "i":
                m2 += i
                k = 0
        m1,m2 = int(m1),int(m2)
        a = n1*m1 - m2*m1
        b = n1*m2 + n2*m1
        return "%d" %a + "%+d" %b +"i"


class Solution:
    def complexNumberMultiply(self, num1: str, num2: str) -> str:
        a1,b1 = map(lambda x:int(x.replace("i",'')),num1.split("+"))
        a2,b2 = map(lambda x:int(x.replace("i",'')),num2.split("+"))
        m = a1 * a2 - b1 * b2
        n = a1 * b2 + a2 * b1
        return "%d" %m + "+" + "%d" %n + "i"



t = Solution()
print(t.complexNumberMultiply("1+1i","1+1i"))
print(t.complexNumberMultiply("0+1i","0+1i"))
