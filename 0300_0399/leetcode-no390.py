class Solution1:
    def lastRemaining(self, n: int) -> int:
        sgn = 1
        a = list(range(1,n+1))
        length = len(a)
        while length != 1:
            if sgn == 1:
                a = [a[i] for i in range(length) if i % 2]
            else:
                if length % 2 == 0:
                    a = [a[i] for i in range(length) if not (i % 2)]
                else:
                    a = [a[i] for i in range(length) if i % 2]
            length //= 2
            sgn = -sgn
        return a[0]


class Solution:
    def lastRemaining(self, n: int) -> int:
        a1 = 1
        k, cnt, step = 0, n ,1
        while cnt > 1:
            if k % 2 == 0:
                a1  += step
            else:
                if cnt % 2:
                    a1 += step
            k += 1
            cnt >>= 1
            step <<= 1
        return a1


t = Solution1()
print(t.lastRemaining(9))
print(t.lastRemaining(16))
print(t.lastRemaining(100))
print(t.lastRemaining(127))
print(t.lastRemaining(5264))
print(t.lastRemaining(5258))
