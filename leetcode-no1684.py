class Solution(object):
    def countConsistentStrings(self, allowed, words):
        """
        :type allowed: str
        :type words: List[str]
        :rtype: int
        """
        sum = 0
        for i in words:
            ok = 1
            for j in i:
                if not j in allowed:
                    ok = 0
                    continue
            if ok:
                sum += 1
        return sum

t = Solution()
print(t.countConsistentStrings("ab",["ad","bd","aaab","baa","badab"]))
print(t.countConsistentStrings("cad",["cc","acd","b","ba","bac","bad","ac","d"]))
