class Solution:
    def getSmallestString(self, n: int, k: int) -> str:
        quotient = 0
        k -= n
        while k > 25:
            k -= 25
            quotient += 1
        first = (n - quotient - 1) * "a"
        second = chr(ord('a') + k)
        last = quotient * "z"
        return first + second + last


t = Solution()
print(t.getSmallestString(3,27))
print(t.getSmallestString(5,73))
print(t.getSmallestString(5,130))

