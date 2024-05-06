class Solution(object):
    def myAtoi(self, s):  #这个题很离谱，完全没有说清楚如何数据处理
        """               #已经不想改了，通过就行
        :type s: str
        :rtype: int
        """
        positive = 1
        num = "0"
        length = len(s)
        for i in range(length):
            print(i,"i")
            if not s[i] in " +-01234567889":
                break
            try:
                if s[i] in "+-" and (not s[i+1] in " 0123456789"):
                    break
            except:
                break
            if s[i] == "-":
                if not s[i+1] in "0123456789":
                    break
                positive = 0
            elif s[i] == "+":
                if not s[i+1] in "0123456789":
                    break
            if s[i] in "0123456789":
                num += s[i]
                try:
                    if s[i+1] in " -+":
                        print("bad")
                        break
                except:
                    pass
        print(num,"num")
        if positive == 0:
            result = -int(num)
        else:
            result = int(num)
        if result >= 2147483648:
            return 2147483647
        elif result <= -2147483648:
            return -2147483648
        return result

t = Solution()
print(t.myAtoi("42"))
print(t.myAtoi("  +  413"))
