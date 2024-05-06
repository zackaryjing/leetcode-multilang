class Solution:
    def convertToBase7(self, num: int) -> str:
        if not num:
            return 0
        if num < 0:
            sign = 0
        else:
            sign = 1
        num = abs(num)
        res = []
        while num > 0:
            res.append(num % 7)
            num //= 7
        ans = "".join(list(map(str,res))[::-1])
        return ('' if sign else "-") + ans

t = Solution()
print(t.convertToBase7(49))
print(t.convertToBase7(100))
print(t.convertToBase7(-100))

