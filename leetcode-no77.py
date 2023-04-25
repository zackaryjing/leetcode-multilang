from itertools import combinations
class Solution(object):
    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        return [i for i in combinations(range(n+1),k)]


t = Solution()
print(t.combine(5,3))