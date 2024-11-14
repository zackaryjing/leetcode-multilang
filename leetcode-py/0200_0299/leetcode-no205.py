from collections import defaultdict
class Solution3:
    def isIsomorphic(self, s: str, t: str) -> bool:
        data = defaultdict(list)
        n1 = len(s)
        n2 = len(t)
        if n1 != n2:
            return False
        # print(m)
        for i in range(n1):
            if (data[s[i]] != [] and data[s[i]][0] != t[i]) or (data[t[i]] != [] and data[t[i]][0] != s[i]):
                return False
            elif data[s[i]] == []:
                data[s[i]] = t[i]
                data[t[i]] = s[i]
            elif data[s[i] == []]:
                return False
        return True

class Solution2:
    def isIsomorphic(self, s: str, t: str) -> bool:
        n1 = len(s)
        n2 = len(t)
        if not n1 == n2:
            return False
        a = set()
        for i in range(n1):
            a.add((s[i],t[i]))
            a.add((s[i], t[i]))
        for j in a:
            if j[::-1] not in a:
                return False
        return True



class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        n1 = len(s)
        n2 = len(t)
        if not n1 == n2:
            return False
        used = []
        pairs = defaultdict(str)
        for i in range(n1):
            if pairs[s[i]] != "":
                if pairs[s[i]] != t[i]:
                    return False
            elif pairs[s[i]] == "":
                if t[i] not in used:
                    pairs[s[i]] += t[i]
                    used.append(t[i])
                else:
                    return False
        return True



t = Solution()
print(t.isIsomorphic("egg","add"))
print(t.isIsomorphic("babc","baba"))
print(t.isIsomorphic("paper","title"))
