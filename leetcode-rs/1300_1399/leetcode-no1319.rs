// problem: https://leetcode.cn/problems/number-of-operations-to-make-network-connected/
struct Solution;

use std::mem::swap;
struct UnionFind {
    parent: Vec<usize>,
    size: Vec<usize>,
    n: usize,
    set_count: usize,
}

impl UnionFind {
    pub fn new(n: usize) -> Self {
        Self {
            parent: (0..n).collect(),
            size: vec![1; n],
            n,
            set_count: n,
        }
    }

    pub fn findset(&mut self, x: usize) -> usize {
        if self.parent[x] == x {
            x
        } else {
            self.parent[x] = self.findset(self.parent[x]);
            self.parent[x]
        }
    }

    pub fn unite(&mut self, x: usize, y: usize) -> bool {
        let mut x = self.findset(x);
        let mut y = self.findset(y);
        if x == y {
            return false;
        }
        if self.size[x] < self.size[y] {
            swap(&mut x, &mut y);
        }
        self.parent[y] = x;
        self.size[x] += self.size[y];
        self.set_count -= 1;
        true
    }
}

impl Solution {
    // [Pass] performance not so good
    pub fn make_connected(n: i32, connections: Vec<Vec<i32>>) -> i32 {
        if n - 1 > connections.len() as i32 {
            return -1;
        }
        let mut uf = UnionFind::new(n as usize);
        for connection in connections {
            uf.unite(connection[0] as usize, connection[1] as usize);
        }
        uf.set_count as i32 - 1
    }
}

impl Solution {
    // [Pass] performance not so good
    pub fn make_connected_2(n: i32, connections: Vec<Vec<i32>>) -> i32 {
        type Graph = Vec<Vec<usize>>;
        let mut graph: Graph = vec![vec![]; n as usize];
        for edge in connections {
            graph[edge[0] as usize].push(edge[1] as usize);
            graph[edge[1] as usize].push(edge[0] as usize);
        }

        struct Dfs<'a> {
            graph: &'a Graph,
            visited: Vec<bool>,
            node_cnt: Vec<usize>,
            edge_cnt: Vec<usize>,
            n: usize,
        }

        impl<'a> Dfs<'a> {
            pub fn new(graph: &'a Graph, n: usize) -> Self {
                Self {
                    graph,
                    visited: vec![false; n],
                    node_cnt: Vec::new(),
                    edge_cnt: Vec::new(),
                    n,
                }
            }
            pub fn dfs(&mut self, i: usize) {
                self.visited[i] = true;
                for ngb in &self.graph[i].clone() {
                    if !self.visited[*ngb] {
                        self.dfs(*ngb);
                        *self.node_cnt.last_mut().unwrap() += 1;
                        *self.edge_cnt.last_mut().unwrap() += self.graph[*ngb].len();
                    }
                }
            }
            pub fn check(&mut self) -> (usize, usize) {
                let mut spare = 0;
                for i in 0..self.n {
                    if !self.visited[i] {
                        self.node_cnt.push(1);
                        self.edge_cnt.push(self.graph[i].len());
                        self.dfs(i);
                        spare +=
                            self.edge_cnt.last().unwrap() / 2 + 1 - self.node_cnt.last().unwrap();
                    }
                }
                (spare, self.node_cnt.len())
            }
        }
        let res = Dfs::new(&graph, n as usize).check();
        if res.0 >= res.1 - 1 {
            res.1 as i32 - 1
        } else {
            -1
        }
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::make_connected(4, vec![vec![0, 1], vec![0, 2], vec![1, 2]])
    );
    println!(
        "{:?}",
        Solution::make_connected(
            6,
            vec![vec![0, 1], vec![0, 2], vec![0, 3], vec![1, 2], vec![1, 3]]
        )
    );
    println!(
        "{:?}",
        Solution::make_connected(6, vec![vec![0, 1], vec![0, 2], vec![0, 3], vec![1, 2]],)
    );
}

//
// Created by zhiya at 6/29/2025 5:34 PM
//
