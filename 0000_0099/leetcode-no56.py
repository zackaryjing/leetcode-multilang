class Solution(object):
    def lengthOfLastWord(self, s):
        """
        :type s: str
        :rtype: int
        """
        k = s.split()
        return len(k.pop())

class Solution(object):
    def lengthOfLastWord(self, s):
        return len(s.split().pop())

t = Solution()
print(t.lengthOfLastWord("Hello World"))