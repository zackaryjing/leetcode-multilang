class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        k = int(num**0.5) + 1
        total = 0
        for i in range(1,k):
            if num % i == 0:
                total += i
                total += (num // i) if ((num // i) != i and i != 1) else 0
                # print(total)
                if total > num:
                    break
        if total == num:
            return True
        else:
            return False
t = Solution()
print(t.checkPerfectNumber(28))