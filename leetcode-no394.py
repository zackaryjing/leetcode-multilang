class Solution:
    def decodeString(self, s: str):
        def getinner(content):
            # print(content)
            inner = ""
            times = ""
            n = len(content)
            i = 0
            while i <= n:
                if i == n:
                    return inner
                char = content[i]
                if char in "abcdefghijklmnopqrstuvwxyz":
                    inner += char
                elif char in "1234567890":
                    times += char
                elif char == "[":
                    temp1,temp2 = getinner(content[i+1:])
                    # print("i am there")
                    # print(times,"KKKK")
                    inner += int(times) * temp1
                    # print(inner,"JJJJ")
                    times = ""
                    i += temp2 + 1
                elif char == "]":
                    # print("im here")
                    return inner,i
                i += 1
        t = getinner(s)
        return t

t = Solution()
print(t.decodeString("3[a]2[bc]"))
print(t.decodeString("3[a2[c]]"))


