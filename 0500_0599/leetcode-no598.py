class Solution(object):
    def maxCount(self, m, n, ops):
        """
        :type m: int
        :type n: int
        :type ops: List[List[int]]
        :rtype: int
        """
        result = [[0 for i in range(m)] for j in range(n)]
        print(result)
        for t in ops:
            for i in range(t[0]):
                for j in range(t[1]):
                    result[i][j] += 1
        print(sum(result,[]))
        return sum(result,[]).count(result[0][0])

class Solution(object):
    def maxCount(self, m, n, ops):

        a = map(lambda x:x[0],ops)
        b = map(lambda x:x[1],ops)
        return min(a)*min(b)


class Solution(object):
    def maxCount(self, m, n, ops):
        """
        :type m: int
        :type n: int
        :type ops: List[List[int]]
        :rtype: int
        """
        if ops == []:
            return m*n
        return min(map(lambda x:x[0],ops))*min(map(lambda x:x[1],ops))


t = Solution()
print(t.maxCount(3,3,[[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3]]))
print(t.maxCount(3,3,[[2,2],[3,3]]))
