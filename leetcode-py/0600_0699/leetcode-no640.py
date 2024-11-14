class Solution3:
    def solveEquation(self, equation: str) -> str:
        effcient = [[],[]]
        rightconstant = []
        leftconstant = []
        processed = equation.split("=")
        for j in [0,1]:
            for i in range(len(processed[j])):
                if processed[j][i] == "x" and i != 0:
                    current = ''
                    for k in range(i-1,-1,-1):
                        if k >= 0 and processed[j][k] in "-+":
                            # print(processed[j][k],"h"+current)
                            effcient[j].append(int(processed[j][k]+'1'))
                            break
                        elif k == 0:
                            # print(processed[j][k],"k"+current)
                            effcient[j].append(int(processed[j][k]+current))
                        else:
                            # print(processed[j][k],"g"+current)
                            current = processed[j][k] + current
                            # print(current)
                    # if processed[j][i-1] == "-":
                    #     effcient[j].append(-1)
                    # else:
                    #     effcient[j].append(1)
                elif processed[j][0] == "x" and i == 0:
                    effcient[j].append(1)
        return effcient

class Solution2:
    def solveEquation(self, equation: str) -> str:
        effcient = [[],[]]
        processed = equation.split("=")
        for j in [0,1]:
            for i in range(len(processed[j])):
                if processed[j][i] == "x" and i != 0:
                    current = ''
                    for k in range(i-1,-1,-1):
                        if k >= 0 and processed[j][k] in "-+":
                            if not current:
                                effcient[j].append(int(processed[j][k]+'1'))
                            else:
                                effcient[j].append(int(processed[j][k] + current))
                            break
                        elif k == 0:
                            effcient[j].append(int(processed[j][k]+current))
                        else:
                            current = processed[j][k] + current
                elif processed[j][0] == "x" and i == 0:
                    effcient[j].append(1)

        left = eval(processed[0].replace("x","0"))
        right = eval(processed[1].replace("x","0"))
        print(left,right)
        return effcient

class Solution:
    def solveEquation(self, equation: str) -> str:
        effcient = [[],[]]
        current = equation[0]
        leftright = equation.split("=")
        for j in [0,1]:
            for i in leftright[j]:
                if i in "-+":
                    if current[-1] == "x" and len(current) != 1:
                        effcient[j].append(int(current))


class Solution:
    def sovleEquation(self, equation: str)->str:
        factor = val = 0
        i,n,sign = 0,len(equation),1
        while i < n:
            if equation[i] == '=':
                sign = -1
                i += 1
                continue
            s = sign
            if equation[i] == "+":
                i += 1
            elif equation[i] == '-':
                s = -s
                i += 1

            num,valid = 0,False
            while i < n and equation[i].isdigit():
                valid = True
                num = num * 10 + int(equation[i])
                i += 1
            if i < n and equation[i] == 'x':
                factor += s * num if valid else s
                i += 1
            else:
                val += s * num

        if factor == 0:
            return "No solution" if val else "Infinite soulution"
        return f"x={-val // factor}"

t = Solution2()
print(t.solveEquation("-x+5-3+x=6+x-2"))
print(t.solveEquation("-23x+5-3-8x=6+x-2"))
print(t.solveEquation("-2x=x"))
print(t.solveEquation("10x=0"))


