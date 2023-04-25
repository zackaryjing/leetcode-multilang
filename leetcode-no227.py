class Solution2:
    def calculate(self, s: str) -> int:
        elements = []
        temp = ""
        for char in s:
            if char in "+-*/":
                elements.extend([int(temp), char])
                temp = ""
            else:
                temp += char
        elements.append(int(temp))
        elements.reverse()
        def dfs(rest:list):
            # print(rest)
            if len(rest) < 2:
                return rest[0]
            if rest[1] == "+":
                return rest[0] + dfs(rest[2:])
            if rest[1] == "-":
                return dfs(rest[2:]) - rest[0]
            if rest[1] == "*":
                return dfs([rest[0] * rest[2]] + rest[3:])
            if rest[1] == "/":
                return dfs([rest[2] // rest[0]] + rest[3:])
        return dfs(elements)

class Solution4:
    def calculate(self, s: str) -> int:
        if not s:
            return 0
        elements = []
        temp = ""
        for char in s:
            if char in "+-*/":
                elements.extend([int(temp), char])
                temp = ""
            elif char != " ":
                temp += char
        elements.append(int(temp))
        def dfs(rest:list):
            # print(rest)
            if len(rest) < 2:
                return [rest[0]]
            if rest[1] == "+":
                return rest[0:2] + dfs(rest[2:])
            if rest[1] == "-":
                return rest[0:2] + dfs(rest[2:])
            if rest[1] == "*":
                return dfs([rest[0] * rest[2]] + rest[3:])
            if rest[1] == "/":
                return dfs([rest[0] // rest[2]] + rest[3:])
        tem = dfs(elements)
        n = len(tem)
        c = [tem[0]]
        # print(tem)
        for i in range(1,n-1,2):
            # print(tem[i],str(tem[i+1]))
            c.append(int(tem[i]+str(tem[i+1])))
        # print(c)
        return sum(c)




class Solution3:
    def calculate(self, s: str) -> int:
        if not s:
            return 0
        elements = []
        temp = ""
        for char in s:
            if char in "+-*/":
                elements.extend([int(temp), char])
                temp = ""
            elif char != " ":
                temp += char
        elements.append(int(temp))
        def dfs(rest:list):
            # print(rest)
            if len(rest) < 2:
                return [rest[0]]
            if rest[1] == "+":
                return rest[0:2] + dfs(rest[2:])
            if rest[1] == "-":
                return rest[0:2] + dfs(rest[2:])
            if rest[1] == "*":
                return dfs([rest[0] * rest[2]] + rest[3:])
            if rest[1] == "/":
                return dfs([rest[0] // rest[2]] + rest[3:])
        tem = dfs(elements)
        n = len(tem)
        total = tem[0]
        for i in range(2,n,2):
            if tem[i-1] == "-":
                total -= tem[i]
            else:
                total += tem[i]
        return total


class Solution:
    def calculate(self,s:str):
        n = len(s)
        stack = []
        preSign = '+'
        num = 0
        for i in range(n):
            if s[i] != ' ' and s[i].isdigit():
                num = num * 10 + ord(s[i]) - ord('0')
            if i == n - 1 or s[i] in '+-*/':
                if preSign == "+":
                    stack.append(num)
                elif preSign == "-":
                    stack.append(-num)
                elif preSign == "*":
                    stack.append(stack.pop() * num)
                else:
                    stack.append(int(stack.pop() / num))
                preSign = s[i]
                num = 0
        return sum(stack)




t = Solution()
print(t.calculate("12/2+7-3*4-1"))
print(t.calculate("3+2*2"))
print(t.calculate(" 3+5 / 2 "))
print(t.calculate("3/2"))
print(t.calculate("3/2*3"))
