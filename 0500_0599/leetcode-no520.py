class Solution:
    def detectCapitalUse(self, word: str) -> bool:
        if len(word) == 1:
            return True
        if 'a' <= word[0] <= 'z':
            for j in word:
                if 'A' <= j <= 'Z':
                    return False
            return True
        else:
            if 'A' <= word[1] <= 'Z':
                start = "A"
                end = "Z"
            else:
                start = "a"
                end = "z"
            for j in word[1:]:
                if j < start or end < j:
                    return False
            return True

t = Solution()
print(t.detectCapitalUse("USA"))
print(t.detectCapitalUse("leetcode"))
print(t.detectCapitalUse("l"))
print(t.detectCapitalUse("L"))
print(t.detectCapitalUse("Lasdf"))
print(t.detectCapitalUse("FlaG"))



