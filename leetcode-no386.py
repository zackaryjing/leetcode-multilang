class Solution2(object):
    def lexicalOrder(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        result = []
        def dfs(begin):
            if begin <= n:
                result.append(begin)
            else:
                return
            for i in range(0, 10):
                if begin * 10 + i <= n:
                    result.append(begin * 10 + i)
                    dfs(begin * 10)
                else:
                    return
        dfs(1)
        return result

class Solution(object):
    def lexicalOrder(self, n):
        res = []
        def dfs(num):
            i = 0
            if num == 0:
                i += 1
            while num + i <= n and i < 10:
                res.append(num + i)
                if (num+i) * 10 <= n:
                    dfs((num+i) * 10)
                i += 1
        dfs(0)
        return res



t = Solution()
print(t.lexicalOrder(110))
print(t.lexicalOrder(2))
