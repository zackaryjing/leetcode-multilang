import string
class Solution2(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        s = s.lower().replace(' ','')
        for c in string.punctuation:
            s = s.replace(c,'')
        return list(s) == [i for i in reversed(s)]

class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        s = s.lower().replace(' ','')
        for c in string.punctuation:
            s = s.replace(c,'')
        return list(s) == [i for i in reversed(s)]
t = Solution()
print(t.isPalindrome("A man, a plan, a canal: Panama"))