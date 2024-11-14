class Solution(object):
    def reverseString(self, s):
        """
        :type s: List[str]
        :rtype: None Do not return anything, modify s in-place instead.
        """
        s.reverse()
        return s

t = Solution()
print(t.reverseString(["h","e","l","l","o"]))