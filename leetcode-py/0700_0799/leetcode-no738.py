class Solution2:
    def monotoneIncreasingDigits(self, n: int) -> int:
        num = str(n)
        for j in num:
            if j < num[0]:
                return int(chr(ord(num[0])-1) + "9"*(len(num)-1))
        start = num[0]
        pos = 0
        while pos < len(num) - 1:
            # print(start,pos)
            start += (num.index(min(num[pos+1:]))-pos)*min(num[pos+1:])
            # print("next min",min(num[pos+1:]))
            pos = num.index(min(num[pos+1:]))
        return int(start)


class Solution:
    def monotoneIncreasingDigits(self, n: int) -> int:
        num = str(n)
        length = len(num)
        ans = ""
        normal = 1
        tmp = 1
        for i in range(length-1):
            if num[i] < num[i+1]:
                ans += num[i] * tmp
                tmp = 1
            elif num[i] == num[i+1]:
                tmp += 1
            else:
                if tmp > 1:
                    ans += str(int(num[i])-1)
                    ans += (length - i + tmp - 2) * "9"
                else:
                    ans += str(int(num[i])-1) * tmp
                    ans += (length - i - 1) * "9"

                normal = 0
                break
        if normal:
            ans += num[length-1] * tmp
        return int(ans)


t = Solution()
s = Solution2()

print(t.monotoneIncreasingDigits(11))
print(t.monotoneIncreasingDigits(999998))
print(t.monotoneIncreasingDigits(332))
print(t.monotoneIncreasingDigits(884))
print(t.monotoneIncreasingDigits(668841))

print(t.monotoneIncreasingDigits(10))
print(t.monotoneIncreasingDigits(1234))
print(t.monotoneIncreasingDigits(166354))
print(t.monotoneIncreasingDigits(16354))
print(t.monotoneIncreasingDigits(120))

# 11
# 899999
# 299
# 799
# 667999
# 9
# 1234
# 159999
# 15999
# 119
