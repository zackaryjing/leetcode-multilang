class Solution:
    def dayOfYear(self, date: str) -> int:
        def isrun(num):
            return (num % 400 == 0) or (num % 4 == 0 and num % 100 != 0)
        add = 0
        data = { 1: 31, 2: 28, 3: 31, 4: 30, 5: 31, 6: 30, 7: 31, 8: 31, 9: 30, 10: 31, 11: 30, 12: 31}
        if isrun(int(date[:4])):
            add = 1
        sum = 0
        for i in range(1,int(date[5:7])):
            if i == 2:
                sum += add
            sum += data[i]
        return sum + int(date[8:])



t = Solution()
print(t.dayOfYear("2019-01-09"))
print(t.dayOfYear("2020-01-03"))
