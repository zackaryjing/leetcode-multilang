class Solution:
    def shortestPalindrome(self, s: str) -> str:
        n = len(s)
        base = 131
        mod = 1000000007
        left = 0
        right = 0
        mul = 1
        best = -1
        for i in range(n):
            left = (left * base + ord(s[i])) % mod
            right = (right + mul * ord(s[i])) % mod
            if left == right:
                best = i
            mul = mul * base % mod
            
        addition = "" if best == n - 1 else s[best + 1:]
        return "".join(reversed(list(addition))) + s
    
t = Solution()
print(t.shortestPalindrome("asdfff"))