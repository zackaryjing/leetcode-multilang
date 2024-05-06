class Solution1(object):
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        ans = [[1]]
        for i in range(1,numRows):
            temp = [1]
            for j in range(i-1):
                temp.append(ans[i-1][j] + ans[i-1][j+1])
            temp.append(1)
            ans.append(temp)
        return ans

class Solution(object):  #优化
    def generate(self, numRows):
        """
        :type numRows: int
        :rtype: List[List[int]]
        """
        ans = [[1]]
        for i in range(1, numRows):
            temp = [1]
            current = ans[i-1]
            for j in range(i - 1):
                temp.append(current[j] + current[j + 1])
            temp.append(1)
            ans.append(temp)
        return ans


def test1():
    t = Solution2()
    t.generate(7)

from timeit import *
t1 = Timer("test1()","from __main__ import test1")
print(t1.timeit(number=100000))