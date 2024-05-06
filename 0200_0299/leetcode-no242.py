class Solution(object):
    def isAnagram(self, s, t):
        return sorted(list(s)) == sorted(list(t))

class Solution(object):
    def isAnagram(self, s, t):
        a = list(t)
        for j in list(s):
            if not j in a:
                return False
            a.remove(j)
        return a == []


class Solution(object):
    def isAnagram(self, s, t):
        a = list(t)
        for j in list(s):
            try:
                a.remove(j)
            except:
                return False
        return a == []

class Solution(object):
    def isAnagram(self, s, t):
        length = len(s)
        if length != len(t):
            return False
        c2,c1 = [0]*26,[0]*26
        for i in range(0,length):
            c1[ord(s[i]) - 97] += 1
            c1[ord(t[i]) - 97] -= 1
        return c1 == c2


t = Solution()
print(t.isAnagram("rcat","rrat"))
