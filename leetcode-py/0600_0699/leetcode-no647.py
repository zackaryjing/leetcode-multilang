class Solution:
    def countSubstrings(self, s: str) -> int:
        n = len(s)
        res = n
        for i in range(n):
            current = 1
            while i-current >= 0 and i+current <= n-1:
                if s[i-current] == s[i+current]:
                    current += 1
                    res += 1
                else:
                    break
            current = 1
            while i - current + 1 >= 0 and i + current <= n -1:
                if s[i - current + 1] == s[i + current]:
                    current += 1
                    res += 1
                else:
                    break
        return res

t = Solution()
print(t.countSubstrings("abc"))
print(t.countSubstrings("aaa"))
