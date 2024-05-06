class Solution(object):
    def titleToNumber(self, columnTitle):
        """
        :type columnTitle: str
        :rtype: int
        """
        result = 0
        data = {"A":1,"B":2,"C":3,"D":4,"E":5,\
                "F":6,"G":7,"H":8,"I":9,"J":10,\
                "K":11,"L":12,"M":13,"N":14,"O":15,\
                "P":16,"Q":17,"R":18,"S":19,"T":20,\
                "U":21,"V":22,"W":23,"X":24,"Y":25,"Z":26}
        length = len(columnTitle)
        for i in range(length):
            result += data[columnTitle[length - i - 1]]*26**i
        return result


t = Solution()
print(t.titleToNumber("AB"))

# t = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
# for i in range(0,26):
#     print('"'+t[i]+'":'+str(i+1)+",",end='')