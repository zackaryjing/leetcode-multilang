class Solution2(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        node = 2*numRows - 2
        if node == 0:
            node = 1
        add = node - len(s)%node
        s += " "*add
        slide = []
        for i in range(0,len(s),node):
            slide.append(s[i:i+node])
        result = ""
        for i in range(numRows):
            for h in slide:
                result += h[i]
                if i > 0 and i < numRows-1:
                    result += h[node - i]
        return result.replace(" ",'')

class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        result = ['']*numRows
        node = numRows - 1
        if node == 0:
            return s
        length = len(s)
        change = 0
        for i in range(0,length):
            if change == 0:
                result[i%node] += s[i]
            else:
                result[node-i%node] += s[i]
            if i%node == node -1 and change == 0:
                change = 1
            elif i%node == node - 1 and change == 1:
                change = 0
        output = ''
        for i in result:
            output += i
        return output
t = Solution()
print(t.convert("PAYPALISHIRING",3))
