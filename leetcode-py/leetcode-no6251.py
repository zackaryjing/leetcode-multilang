from itertools import combinations
class Solution(object):
    def countPalindromes(self, s):
        """
        没思路暴力破解一波
        :type s: str
        :rtype: int
        """
        sum = 0
        alist = combinations(s,5)
        for i in alist:
            if [i[0],i[1]] == [i[4],i[3]]:
                sum += 1
        return sum

t = Solution()
print(t.countPalindromes("101011"))