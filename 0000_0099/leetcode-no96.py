nodes = [1]
for n in range(2,19):
    nodes.append(int((4*n-2)/(n+1)*nodes[n-2]))

class Solution:
    def numTrees(self, n: int) -> int:
        return nodes[n-1]

t = Solution()
print(t.numTrees(3))

