class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        return s in (s*2)[1:len(s)*2 - 1]
    
t = Solution()
print(t.repeatedSubstringPattern("asdfasdf"))
print(t.repeatedSubstringPattern("asefasdf"))
