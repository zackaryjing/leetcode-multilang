class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        addedList = list(s)
        n = len(s)
        for i in range(0,2*n+1,2):
            addedList.insert(i,None)
        print(addedList)
        current = 0
        center = 1
        for i in range(1,2*n):
            r = 0
            while (i - r >= 0) and (i + r <= 2*n):
                if (not addedList[i-r] == addedList[i+r]) :
                    print(addedList[i-r],addedList[i],addedList[i+r],i,r)
                    if r-2 > current:
                        current = r-2
                        center = i
                    break
                elif (i - r == 0) or (i + r == 2*n):
                    print(addedList[i - r], addedList[i], addedList[i + r], i, r)
                    if r-1 > current:
                        current = r-1
                        center = i
                r += 1
        return s[(center-current-1)//2:(center+current+1)//2]

class Solution2(object): #对原有方法进行优化
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        addedList = list(s)
        n = len(s)
        for i in range(1,2*n-1,2):
            addedList.insert(i,None)
        current = 0
        center = 1
        for i in range(0,2*n-1):
            r = 0
            start = 0
            end = 0
            while (start >= 0) and (end <= 2*n-2):
                if (not addedList[start] == addedList[end]) :
                    if r-2 > current:
                        current = r-2
                        center = i
                    break
                r += 1
                start = i - r
                end = i + r
            if ((start < 0) or (end > 2*n-2)):
                if r - 1 > current:
                    current = r - 1
                    center = i
        return s[(center-current)//2:(center+current+2)//2]

t = Solution2()
print(t.longestPalindrome("ahhfkhkfha"))