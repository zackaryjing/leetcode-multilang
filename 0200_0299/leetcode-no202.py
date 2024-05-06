class Solution(object):
    def isHappy(self, n):
        process = []
        while True:
            a = map(int,list(str(n)))
            middle = 0
            for i in a:
                middle += i**2
            if middle == 1:
                return True
            if middle in process:
                return False
            n = middle
            process.append(middle)


t = Solution()
print(t.isHappy(19))