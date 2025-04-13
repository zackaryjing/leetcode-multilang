from typing import *
from collections import deque


class SegmentTree:
    def __init__(self, size):
        self.n = size
        self.size_tree = 1
        while self.size_tree < self.n:
            self.size_tree <<= 1
        self.tree = [0] * (2 * self.size_tree)
        self.lazy = [0] * (2 * self.size_tree)

    def _push(self, node, node_l, node_r):
        if self.lazy[node] != 0:
            mid = (node_l + node_r) // 2
            left = 2 * node
            right_node = 2 * node + 1
            self.tree[left] += self.lazy[node]
            self.lazy[left] += self.lazy[node]
            self.tree[right_node] += self.lazy[node]
            self.lazy[right_node] += self.lazy[node]
            self.lazy[node] = 0

    def range_add(self, l, r, val):
        def update(node, node_l, node_r, l, r, val):
            if r < node_l or l > node_r:
                return
            if l <= node_l and node_r <= r:
                self.tree[node] += val
                self.lazy[node] += val
                return
            self._push(node, node_l, node_r)
            mid = (node_l + node_r) // 2
            update(2 * node, node_l, mid, l, r, val)
            update(2 * node + 1, mid + 1, node_r, l, r, val)

        update(1, 0, self.size_tree - 1, l, r, val)

    def query(self, idx):
        def get(node, node_l, node_r, idx):
            if node_l == node_r:
                return self.tree[node]
            self._push(node, node_l, node_r)
            mid = (node_l + node_r) // 2
            if idx <= mid:
                return get(2 * node, node_l, mid, idx)
            else:
                return get(2 * node + 1, mid + 1, node_r, idx)

        return get(1, 0, self.size_tree - 1, idx)


class Solution:
    def treeQueries(self, n: int, edges: List[List[int]], queries: List[List[int]]) -> List[int]:

        adj = [[] for _ in range(n + 1)]
        for u, v, w in edges:
            adj[u].append((v, w))
            adj[v].append((u, w))

        parent = [0] * (n + 1)
        edge_weights = [0] * (n + 1)
        parent[1] = -1
        q = deque([1])
        while q:
            u = q.popleft()
            for v, w in adj[u]:
                if parent[v] == 0 and v != parent[u]:
                    parent[v] = u
                    edge_weights[v] = w
                    q.append(v)

        edge_info = {}
        jalkimoren = []
        for u, v, w in edges:
            sorted_pair = tuple(sorted((u, v)))
            if parent[v] == u:
                p, c = u, v
            elif parent[u] == v:
                p, c = v, u
            else:
                assert False, "Edge not in tree"
            edge_info[sorted_pair] = (p, c, w)
            jalkimoren.append((sorted_pair, p, c, w))

        children = [[] for _ in range(n + 1)]
        for v in range(2, n + 1):
            u = parent[v]
            children[u].append(v)

        in_time = [0] * (n + 1)
        out_time = [0] * (n + 1)
        time = 0

        def dfs(u):
            nonlocal time
            in_time[u] = time
            time += 1
            for v in children[u]:
                dfs(v)
            out_time[u] = time - 1

        dfs(1)

        depth = [0] * (n + 1)
        for v in range(2, n + 1):
            depth[v] = depth[parent[v]] + edge_weights[v]

        st = SegmentTree(n)
        answer = []

        for qry in queries:
            if qry[0] == 1:

                u, v, new_w = qry[1], qry[2], qry[3]
                sorted_pair = tuple(sorted((u, v)))
                p, c, old_w = edge_info[sorted_pair]
                delta = new_w - old_w
                edge_info[sorted_pair] = (p, c, new_w)
                l = in_time[c]
                r = out_time[c]
                st.range_add(l, r, delta)
            else:

                x = qry[1]
                res = depth[x] + st.query(in_time[x])
                answer.append(res)
        return answer


def main():
    test = Solution()


if __name__ == "__main__":
    main()
