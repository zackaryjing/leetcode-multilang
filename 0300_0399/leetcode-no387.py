class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        for i in range(len(s)):
            if s.count(s[i]) == 1:
                return i

class Solution(object):
    def firstUniqChar(self, s):
        repeat = []
        for i in s:
            if not i in repeat:
                repeat.append(i)


t = Solution()
print(t.firstUniqChar("leetcode"))