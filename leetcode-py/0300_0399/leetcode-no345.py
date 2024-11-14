class Solution:
    def reverseVowels(self, s: str) -> str:
        n = len(s)
        temp = []
        yuan = []
        t = list(s)
        for i in range(n):
            if s[i] in "aeiouAEIOU":
                yuan.append(i)
                temp.append(s[i])
        for k in yuan:
            t[k] = temp.pop()
        return "".join(t)

t = Solution()
print(t.reverseVowels("hello"))
print(t.reverseVowels("leetcode"))
print(t.reverseVowels("aA"))

