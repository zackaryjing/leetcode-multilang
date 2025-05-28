// problem: https://leetcode.cn/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i/?envType=daily-question&envId=2025-05-28
struct Solution;

use std::cell::RefCell;
use std::cmp::max;
use std::collections::HashSet;
impl Solution {
    // [Pass] Perf ok now. Writing rust hurts my soul.
    pub fn max_target_nodes(edges1: Vec<Vec<i32>>, edges2: Vec<Vec<i32>>, k: i32) -> Vec<i32> {
        let n = edges1.len() + 1;
        let m = edges2.len() + 1;
        let mut graph1: Vec<Vec<i32>> = vec![Vec::new(); n];
        let mut graph2: Vec<Vec<i32>> = vec![Vec::new(); m];
        for edge in edges1 {
            graph1[edge[1] as usize].push(edge[0]);
            graph1[edge[0] as usize].push(edge[1]);
        }
        for edge in edges2 {
            graph2[edge[0] as usize].push(edge[1]);
            graph2[edge[1] as usize].push(edge[0]);
        }
        let mut adjacent1: Vec<i32> = vec![0; n];

        struct Helper {
            graph: Vec<Vec<i32>>,
            k: i32,
            vis: RefCell<i32>
        }
        let mut helper1 = Helper {
            graph: graph1,
            k,
            vis: RefCell::new(0)
        };
        let mut helper2 = Helper {
            graph: graph2,
            k: k - 1,
            vis: RefCell::new(0)
        };
        impl Helper {
            fn dfs(&self, root: i32) -> i32 {
                *self.vis.borrow_mut() = 0;
                if self.k >= 0 {
                    self.inner(root, 0,-1);
                }
                *self.vis.borrow_mut()
            }
            fn inner(&self, root: i32, depth: i32,par : i32) {
                *self.vis.borrow_mut() += 1;
                if depth < self.k {
                    for &child in &self.graph[root as usize] {
                        if child != par {
                            self.inner(child, depth + 1,root);
                        }
                    }
                }
            }
        }

        for i in 0..n {
            adjacent1[i] = helper1.dfs(i as i32);
        }
        let mut max_val = 0;
        for i in 0..m {
            max_val = max(max_val,helper2.dfs(i as i32));
        }

        let mut res = vec![0;n];
        for i in 0..n {
            res[i] = adjacent1[i] + max_val;
        }
        res
    }
}

impl Solution {
    // [Pass] Performance is bad.
    pub fn max_target_nodes_2(edges1: Vec<Vec<i32>>, edges2: Vec<Vec<i32>>, k: i32) -> Vec<i32> {
        let n = edges1.len() + 1;
        let m = edges2.len() + 1;
        let mut graph1: Vec<HashSet<i32>> = vec![HashSet::new(); n];
        let mut graph2: Vec<HashSet<i32>> = vec![HashSet::new(); m];
        for edge in edges1 {
            graph1[edge[0] as usize].insert(edge[1]);
            graph1[edge[1] as usize].insert(edge[0]);
        }
        for edge in edges2 {
            graph2[edge[0] as usize].insert(edge[1]);
            graph2[edge[1] as usize].insert(edge[0]);
        }
        let mut adjacent1: Vec<i32> = vec![0; n];

        struct Helper {
            graph: Vec<HashSet<i32>>,
            k: i32,
            vis: RefCell<HashSet<i32>>,
        }
        let mut helper1 = Helper {
            graph: graph1,
            k,
            vis: RefCell::new(HashSet::new()),
        };
        let mut helper2 = Helper {
            graph: graph2,
            k: k - 1,
            vis: RefCell::new(HashSet::new()),
        };
        impl Helper {
            fn dfs(&mut self, root: i32) -> usize {
                self.vis.borrow_mut().clear();
                if self.k >= 0 {
                    self.inner(root, 0);
                }
                self.vis.borrow_mut().len()
            }
            fn inner(&self, root: i32, depth: i32) {
                self.vis.borrow_mut().insert(root);
                if depth < self.k {
                    for &child in &self.graph[root as usize] {
                        if !self.vis.borrow_mut().contains(&child) {
                            self.inner(child, depth + 1);
                        }
                    }
                }
            }
        }

        for i in 0..n {
            adjacent1[i] = helper1.dfs(i as i32) as i32;
        }
        let mut max_val = 0;
        for i in 0..m {
            max_val = max(max_val,helper2.dfs(i as i32) as i32);
        }

        let mut res = vec![0;n];
        for i in 0..n {
            res[i] = adjacent1[i] + max_val;
        }
        res
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::max_target_nodes(
            vec![vec![0, 1], vec![0, 2], vec![2, 3], vec![2, 4]],
            vec![
                vec![0, 1],
                vec![0, 2],
                vec![0, 3],
                vec![2, 7],
                vec![1, 4],
                vec![4, 5],
                vec![4, 6]
            ],
            2
        )
    );
    println!(
        "{:?}",
        Solution::max_target_nodes(
            vec![vec![0, 1], vec![0, 2], vec![0, 3], vec![0, 4]],
            vec![vec![0, 1], vec![1, 2], vec![2, 3]],
            1
        )
    );
    println!(
        "{:?}",
        Solution::max_target_nodes(
            vec![vec![0, 1]],
            vec![vec![0, 1]],
            0
        )
    );
}

//
// Created by zhiya at 2025/5/28 15:03
//
