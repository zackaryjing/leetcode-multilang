# Definition for a Node.
from typing import *
from collections import deque
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []

class Solution3:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node:
            return None
        tovis = deque()
        tovis.append(node)
        begin = Node(1)
        vis = set()
        vis.add(1)
        created = {1:begin}
        while tovis:
            cur = tovis.popleft()
            cop = created[cur.val]
            for i in cur.neighbors:
                if i.val in created.keys():
                    cop.neighbors.append(created[i.val])
                else:
                    tmp = Node(i.val)
                    created[i.val] = tmp
                    cop.neighbors.append(tmp)
                if i.val not in vis:
                    vis.add(i.val)
                    tovis.append(i)
        return begin
'''
use to test offical code
'''
class Solution:
    def __init__(self):
        self.visited = {}
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node:
            return node
        if node in self.visited:
            return self.visited[node]
        clone_node = Node(node.val,[])
        self.visited[node] = clone_node
        self.visited[node] = clone_node
        if node.neighbors:
            clone_node.neighbors = [self.cloneGraph(n) for n in node.neighbors]
            
        return clone_node

   
node1 = Node(1)
node2 = Node(2)
node3 = Node(3)
node4 = Node(4)
node1.neighbors.extend([node2,node3])
node2.neighbors.extend([node1,node3,node4])
node3.neighbors.extend([node1,node2,node4])
node4.neighbors.extend([node3,node2])


t = Solution()

def bfs(k):
    tovis = deque([k])
    vis = set()
    vis.add(1)
    while tovis:
        cur = tovis.popleft()
        print(cur.val)
        for i in cur.neighbors:
            if i.val not in vis:
                vis.add(i.val)
                tovis.append(i)
        
    
k = t.cloneGraph(node1)
bfs(k)
