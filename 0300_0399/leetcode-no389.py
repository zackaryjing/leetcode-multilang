class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        t = list(t)
        for i in list(s):
            t.remove(i)
        return t[0]


t = Solution()
print(t.findTheDifference("abcd","abcdr"))