class Solution:
    def maxPower(self, s: str) -> int:
        start = s[0]
        maxlength = 0
        current = 0
        for i in s:
            if i != start:
                if current > maxlength:
                    maxlength = current
                start = i
                current = 1
            else:
                current += 1
        if maxlength < current:
            maxlength = current
        return maxlength

t = Solution()
print(t.maxPower("leetcode"))
print(t.maxPower("eetcode"))
print(t.maxPower("abbcccddddeeeeedcba"))
print(t.maxPower("a"))
