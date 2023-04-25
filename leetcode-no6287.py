class Solution:
    def categorizeBox(self, length: int, width: int, height: int, mass: int) -> str:
        volum = 0
        if length >= 10000 or width >= 10000 or height >= 10000 or length * width * height>= 1000000000:
            volum = 1
        weight = 0
        if mass >= 100:
            weight = 1
        if volum and weight:
            return "Both"
        elif volum:
            return "Bulky"
        elif weight:
            return "Heavy"
        else:
            return "Neither"

t = Solution()
print(t.categorizeBox(10000,35,700,10))
