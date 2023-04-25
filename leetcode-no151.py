class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join(reversed(s.split()))

t = Solution()
print(t.reverseWords("the sky is blue"))