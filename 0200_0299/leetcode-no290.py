from collections import *
class Solution(object):
    def wordPattern(self, pattern, s):
        """
        :type pattern: str
        :type s: str
        :rtype: bool
        """
        s = s.split()
        two = []
        for h in [pattern,s]:
            length = len(h)
            types = defaultdict(list)
            for i in range(length):
                types[h[i]].append(i)
            two.append(types)
        if sorted(two[0].values()) == sorted(two[1].values()):
            return True
        return False
t = Solution()
print(t.wordPattern("abcabc","aaa bbb ccc aaa bbb ccc hh"))