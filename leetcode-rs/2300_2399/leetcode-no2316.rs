// problem: https://leetcode.cn/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/
struct Solution;

use std::collections::HashSet;
use std::mem::swap;
struct UnitFindSet {
    parent: Vec<usize>,
    rank: Vec<usize>,
}

impl UnitFindSet {
    pub fn new(n: usize) -> Self {
        Self {
            parent: (0..n).collect(),
            rank: vec![1; n],
        }
    }
    pub fn find(&mut self, index: usize) -> usize {
        if self.parent[index] != index {
            self.parent[index] = self.find(self.parent[index]);
        }
        self.parent[index]
    }

    pub fn unite(&mut self, index1: usize, index2: usize) {
        let (mut from, mut to) = (self.find(index1), self.find(index2));
        if from == to {
            return;
        }
        if self.rank[from] > self.rank[to] {
            swap(&mut from, &mut to);
        }
        self.parent[from] = to;
        self.rank[to] += self.rank[from];
    }

    pub fn compress(&mut self, index: usize) -> usize {
        if self.parent[index] != index {
            let res = self.find(self.parent[index]);
            self.parent[index] = res;
            res
        } else {
            index
        }
    }
}

impl Solution {
    pub fn count_pairs(n: i32, edges: Vec<Vec<i32>>) -> i64 {
        let n = n as usize;
        let mut s = UnitFindSet::new(n);
        for edge in edges {
            s.unite(edge[0] as usize, edge[1] as usize);
        }

        for i in 0..n {
            s.compress(i);
        }
        let shown: HashSet<usize> = HashSet::from_iter(s.parent.into_iter());
        let mut sq_sum = 0;
        let mut sum = 0;
        for k in shown {
            let r = s.rank[k];
            sum += r;
            sq_sum += r * r;
        }
        ((sum * sum - sq_sum) / 2) as i64
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::count_pairs(
            7,
            vec![vec![0, 2], vec![0, 5], vec![2, 4], vec![1, 6], vec![5, 4]]
        )
    );
    println!(
        "{:?}",
        Solution::count_pairs(3, vec![vec![0, 1], vec![0, 2], vec![1, 2]])
    );
}

//
// Created by zhiya at 7/22/2025 1:26 PM
//
