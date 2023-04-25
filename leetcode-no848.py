class Solution:
    def shiftingLetters(self, s: str, shifts: list[int]) -> str:
        n = len(shifts)
        res = []
        total = 0
        for i in range(n-1,-1,-1):
            total += shifts[i]
            res.append(chr(97+(ord(s[i])+total-97)%26))
        return ''.join(reversed(res))
t = Solution()
print(t.shiftingLetters("abc",[3,5,9]))
print(t.shiftingLetters("aaa",[1,2,3]))
print(t.shiftingLetters("bad",[10,20,30]))
