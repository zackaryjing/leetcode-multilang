class Solution2:
    def longestValidParentheses(self, s: str) -> int:
        def check(s,lbracket,rbracket):
            print(s)
            ans = 0
            current = 0
            left = 0
            right = 0
            for i in s:
                if i == lbracket:
                    left += 1
                elif i == rbracket:
                    right += 1
                    if left >= right:
                        current += 2
                if left < right:
                    left = right = 0
                    if current > ans:
                        ans = current
                        current = 0
                # print(i,current,ans)
            if current > ans:
                ans = current
            return ans
        ans1 = check(s,"(",")")
        ans2 = check(s[::-1],")","(")
        return min(ans1,ans2)

class Solution:
    def longestValidParentheses(self, s: str) -> int:
        def check(s,lbracket,rbracket):
            for i in s:
                if i == lbracket:
                    a = [sdasdf]







t = Solution()
print(t.longestValidParentheses("))))())()()(()"))
print(t.longestValidParentheses("(()"))
print(t.longestValidParentheses(")()()"))
print(t.longestValidParentheses("()(()"))
