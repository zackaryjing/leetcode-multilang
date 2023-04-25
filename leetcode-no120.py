class Solution(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        length = len(triangle)
        for i in range(1,length):
            triangle[i][0] += triangle[i-1][0]
            for j in range(1,len(triangle[i])-1):
                triangle[i][j] += min(triangle[i-1][j-1],triangle[i-1][j])
            triangle[i][-1] += triangle[i-1][-1]
        return min(triangle[-1])

t = Solution()
print(t.minimumTotal([[2],[3,4],[6,5,7],[4,1,8,3]]))

