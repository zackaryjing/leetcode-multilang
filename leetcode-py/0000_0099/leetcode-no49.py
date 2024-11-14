from collections import *
class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        data = defaultdict(list)
        for i in strs:
            data[''.join(sorted(i))] += [i]
        return data.values()


t = Solution()
print(t.groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"]))