class Solution(object):
    def countBinarySubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        begin = s[0]
        data = []
        mid = 0
        for i in s:
            if i == begin:
                mid += 1
            else:
                begin = i
                data.append(mid)
                mid =1
        data.append(mid)
        sum = 0
        for i in range(len(data)-1):
            sum += min(data[i],data[i+1])
        return sum

t = Solution()
print(t.countBinarySubstrings("00110011"))
print(t.countBinarySubstrings("10101"))
print(t.countBinarySubstrings("1110001010111"))
