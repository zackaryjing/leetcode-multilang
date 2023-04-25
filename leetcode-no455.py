class Solution(object):
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        g.sort(reverse=True)
        s.sort()
        res = 0
        for i in s:
            for j in g:
                if j <= i:
                    res += 1
                    g.remove(j)
                    break
        return res

class Solution(object):
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """
        res = 0
        s.sort()
        g.sort()
        for i in s:
            for j in g:
                if j<=i:
                    g.remove(i)
                    res += 1
                    break
        return res
t = Solution()
print(t.findContentChildren([1,2,3],[1,1]))
print(t.findContentChildren([1,2],[1,2,3]))
