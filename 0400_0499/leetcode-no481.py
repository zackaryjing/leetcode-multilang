class Solution:
    def magicalString(self, n: int) -> int:
        s = "122"
        times = 1
        current = "2"
        if n <= 3:
            return 1
        while (times := (times + 1)) < int(n*1.5)+10:
            current = "2" if current == "1" else "1"
            s += current * int(s[times])
        return s[:n].count("1")

t = Solution()
print(t.magicalString(1))
print(t.magicalString(2))
print(t.magicalString(3))
print(t.magicalString(4))

# for i in range(1,280):
#     if a[i:].startswith(a[1:i]):
#         print("t",a[i:])

# s = []
# b = 1
# i = 0
# mid = []
# while i < len(a)-1:
#     if a[i] == a[i+1]:
#         mid.append(a[i:i+2])
#         i += 2
#         b += 1
#     else:
#         mid.append(a[i])
#         i += 1
#         b += 1
#     if b % 5 == 0:
#         b = 1
#         s.append(mid[:])
#         mid = []
#
# print(s)
