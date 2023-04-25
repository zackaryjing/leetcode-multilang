
class Solution:
    def findRedundantConnection(self,edges:list[list[int]])->list[int]:
        n = len(edges)
        parent = list(range(n + 1))
        def find(index:int)->int:
            if parent[index] != index:
                parent[index] = find(parent[index])
            return parent[index]

        def union(index1:int,index2:int):
            parent[find(index1)] = find(index2)

        for node1,node2 in edges:
            if find(node1) != find(node2):
                union(node1, node2)
            else:
                print(parent)
                return [node1,node2]
        return []

t = Solution()
print(t.finRedundantConnections([[1,2], [2,3], [3,4], [1,4], [1,5]]))
print(t.finRedundantConnections([[1,2], [1,3], [2,4], [3,6], [2,5], [3,7], [5,8], [7,9], [8,9]]))
print(t.finRedundantConnections([[1,2], [1,3], [2,3]]))
