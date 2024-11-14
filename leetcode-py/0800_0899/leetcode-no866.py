def isprime(t):
    if t == 1:
        return False
    k = int(t ** 0.5) + 1
    for i in range(2, k):
        if t % i == 0:
            return False
    return True


def generate(num):
    return int(str(num) + str(num)[::-1][1:])


class Solution:
    def primePalindrome(self, n: int) -> int:
        data = [2,3,5,7,11]
        for h in data:
            if h >= n:
                return h
        length = len(str(n))
        start = int("1" + "0" * ((length - 1) // 2))
        while True:
            if (tmp := generate(start)) > n and isprime(tmp):
                return tmp
            start += 1


t = Solution()
print(t.primePalindrome(7))
print(t.primePalindrome(9))
print(t.primePalindrome(44))
