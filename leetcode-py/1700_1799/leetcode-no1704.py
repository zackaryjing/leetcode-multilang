class Solution(object):
    def halvesAreAlike(self, s):
        """
        :type s: str
        :rtype: bool
        """
        length = len(s)//2
        vowel = list("aeiouAEIOU")
        firstpart = s[0:length]
        secondpart = s[length:]
        a,b = 0,0
        for i in vowel:
            a += firstpart.count(i)
            b += secondpart.count(i)
        if a == b:
            return True
        else:
            return False

t = Solution()
print(t.halvesAreAlike("textbook"))