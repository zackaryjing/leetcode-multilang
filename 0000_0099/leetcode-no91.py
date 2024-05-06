class Solution(object):
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        length = len(s)
        if s[0] == "0":
            return 0
        if length < 2:
            return 1
        if s[1] == "0":
            lastsingle = 0
        else:
            lastsingle = 1
        total = 1
        if s[0] > "2" and s[1] == "0":
            return 0
        for i in range(1, length - 1):
            # print(total,lastsingle)
            if s[i - 1] < "2" and s[i + 1] != "0":
                if not s[i] == "0":
                    total, lastsingle = total + lastsingle, total
                else:
                    total += lastsingle
                    lastsingle = 0
            elif s[i - 1] == "2" and s[i] < "7" and s[i + 1] != "0":
                if not s[i] == "0":
                    total, lastsingle = total + lastsingle, total
                else:
                    total += lastsingle
                    lastsingle = 0
            elif s[i + 1] == "0":
                if s[i] > "2" or s[i] == "0":
                    return 0
                lastsingle = 0
            else:
                lastsingle = total
        if s[-2] < "2":
            total = total + lastsingle
        elif s[-2] == "2" and s[-1] < "7":
            total = total + lastsingle
        return total

t = Solution()
print(t.numDecodings("1232671"))
print(t.numDecodings("121212"))
print(t.numDecodings("101010"))
print(t.numDecodings("06"))
print(t.numDecodings("60"))
print(t.numDecodings("2101"))
