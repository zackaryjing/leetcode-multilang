from typing import *
import math

data = {
    1: "One", 2: "Two", 3: "Three", 4: "Four", 5: "Five", 6: "Six", 7: "Seven", 8: "Eight", 9: "Nine", 10: "Ten",
    11: "Eleven", 12: "Twelve", 13: "Thirteen", 14: "Fourteen", 15: "Fifteen", 16: "Sixteen", 17: "Seventeen",
    18: "Eighteen", 19: "Nineteen", 20: "Twenty", 30: "Thirty", 40: "Forty", 50: "Fifty", 60: "Sixty", 70: "Seventy",
    80: "Eighty", 90: "Ninety", 100: "Hundred", 1000: "Thousand", 1000000: "Million", 1000000000: "Billion"
}
keys = data.keys()

class Solution:
    def numberToWords(self, num: int) -> str:
        if num == 0:
            return "Zero"
        times = 0
        ans = ""
        suffix = ["","Thousand","Million","Billion"]
        while num != 0:
            # print(times)
            current = num % 1000
            tmp = ""
            if current // 100 != 0:
                tmp = " " + data[current // 100] + " Hundred"
            if current % 100:
                if (current % 100) in keys:
                    tmp += " " + data[current % 100]
                else:
                    tmp += " " + data[current % 100 - current % 10] + " " + data[current % 10]
            if tmp != "":
                ans = tmp + " " + suffix[times] + ans
            times += 1
            num //= 1000
        ans = ans.strip()
        return ans
    
t = Solution()
print(t.numberToWords(1000010))
print(t.numberToWords(1000000))
print(t.numberToWords(1))
print(t.numberToWords(1001))
print(t.numberToWords(1000))
print(t.numberToWords(100))
print(t.numberToWords(12345))
print(t.numberToWords(1234567))




            
            
            