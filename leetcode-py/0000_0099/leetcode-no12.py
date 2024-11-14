
class Solution2:
    def intToRoman(self, num: int) -> str:
        data = {1:"I",5:"V",10:"X",50:"L",100:"C",500:"D",1000:"M"}
        # print(data.values())
        if num in data.keys():
            return data[num]
        char = ['I', 'V', 'X', 'L', 'C', 'D', 'M']
        ans = ""
        ans += "M" * (num // 1000)
        num %= 1000
        for i in range(6,0,-2):
            cur = 10 ** (i // 2 - 1)
            # print(cur,i,num)
            if num // cur == 9:
                ans += char[i - 2] + char[i]
            elif num // cur == 4:
                ans += char[i - 2] + char[i - 1]
            elif num // cur == 5:
                ans += char[i - 1]
            else:
                if num > 5 * cur:
                    ans += char[i-1]
                    num %= (5 * cur)
                ans += char[i - 2] * (num // cur)
            num %= cur
        return ans
h = Solution2()
Solution2.intToRoman(h,12)
        # print(list(reversed(data)))
"""
D
LVIII
MCMXCIV
III
IV
IX
"""

class Solution:
    def intToRoman(self, num: int) -> str:
        data = {1:"I",5:"V",10:"X",50:"L",100:"C",500:"D",1000:"M"}
        if num in data.keys():
            return data[num]
        number = str(num)
        n = len(number)
        ans = ""
        ans += "M" * (num // 1000)
        num %= 1000
        if num // 100 == 9:
            ans += "CM"
        elif num // 100 == 4:
            ans += "CD"
        elif num // 100 == 5:
            ans += "D"
        else:
            if num > 500:
                ans += "D"
                num %= 500
            ans += "C" * (num // 100)
        num %= 100
        if num // 10 == 9:
            ans += "XC"
        elif num // 10 == 4:
            ans += "XL"
        elif num // 10 == 5:
            ans += "L"
        else:
            if num > 50:
                ans += "L"
                num %= 50
            ans += "X" * (num // 10)
        num %= 10
        if num == 9:
            ans += "IX"
        elif num == 4:
            ans += "IV"
        elif num == 5:
            ans += "V"
        else:
            if num > 5:
                ans += "V"
                num %= 5
            ans += "I" * num
        return ans
    
        
t = Solution2()
print(t.intToRoman(500))
print(t.intToRoman(58))
print(t.intToRoman(1994))
print(t.intToRoman(3))
print(t.intToRoman(4))
print(t.intToRoman(9))


