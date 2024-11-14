class Solution2(object):
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        result = []
        times = 0
        length = len(s)
        current = 0
        def substring(string,times,current):
            times += 1
            print("*"*times*5)
            for i in [1,2,3]:
                sub = string[:i]
                print(sub)
                current += i
                if current < length and times<4 and sub and (not sub.startswith("0")) and int(sub)<=255:
                    substring(string[i:],times,current)
                if times == 4:
                    pass

        return substring(s,0,0)


# t = Solution()
# print(t.restoreIpAddresses("123124234134"))

end = 8
# for i in range(1,5):
#     for j in range(1, 5):
#         for k in range(1, 5):
#             for l in range(1, 5):
#                 if (i + j + k + l) == end:
#                     print((i,j,k,l))

class Solution(object):
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        length = len(s)
        types = [(i,j,k,l) for i in range(1,5) for j in range(1,5) for k in range(1,5) for l in range(1,5) if (i+j+k+l)==length]
        ans = []
        for t in types:
            current = []
            now = 0
            for y in t:
                middle = s[now:now+y]
                if int(middle)<=255 and not (middle.startswith("0") and not len(middle)==1):
                    current.append(middle)
                now = now+y
            if len(current) == 4:
                ans.append('.'.join(current))
        return ans

t = Solution()
print(t.restoreIpAddresses("121011"))