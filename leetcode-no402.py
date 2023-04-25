class Solution2:
    def removeKdigits(self, num: str, k: int) -> str:
        for i in range(k):
            n = len(num)
            minum = num[:n-1]
            for j in range(n):
                s = num[:j]+num[j+1:]
                if s < minum:
                    minum = s
            num = minum
        if num == '':
            return "0"
        return str(int(num))

class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        stack = []
        for i in num:
            while k and stack and i < stack[-1]:
                stack.pop()
                k -= 1
            stack.append(i)
        if k != 0:
            del stack[-k:]
        a = ''.join(stack)
        if a == '':
            return '0'
        return str(int(a))


t = Solution()
print(t.removeKdigits('10200',1))
print(t.removeKdigits('2189',2))
print(t.removeKdigits('12345434567876789',3))
12334567876789
12345434566789