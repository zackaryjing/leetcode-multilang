class Solution:
    def maximumScore(self, a: int, b: int, c: int) -> int:
        data = [a,b,c]
        data.sort()
        if data[0] + data[1] >= data[2]:
            return sum(data) // 2
        else:
            return data[0] + data[1]

t = Solution()
print(t.maximumScore(2,4,6))
print(t.maximumScore(4,4,6))
print(t.maximumScore(1,8,8))
