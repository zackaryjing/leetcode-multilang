class Solution:
    def reverseStr(self, s: str, k: int) -> str:
        n = len(s)
        ans = ""
        for i in range(0, n, 2 * k):
            # print(i)
            # print(i + k - 1,i - 1)
            # print(s[i + k - 1:i - 1:-1])

            ans += "".join(reversed(s[i: i + k]))
            ans += s[i + k: i + 2 * k]
        return ans


test = Solution()
print(test.reverseStr("abcdefg", 2))
