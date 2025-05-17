use std::sync::atomic::AtomicUsize;

// problem: https://leetcode.cn/problems/min-cost-to-connect-all-points/
struct Solution;


use std::{collections::BinaryHeap, i32};

#[derive(Eq, PartialEq, Debug)]
struct Cost((usize, i32));

impl Ord for Cost{
    fn cmp(&self, other: &Self) -> std::cmp::Ordering {
        other.0.1.cmp(&self.0.1)
    }
}

impl PartialOrd for Cost{
    fn partial_cmp(&self, other: &Self) -> Option<std::cmp::Ordering> {
        Some(self.cmp(other))
    }
}

impl Solution {
    pub fn min_cost_connect_points(points: Vec<Vec<i32>>) -> i32 {
        let n = points.len();
        let mut visited: Vec<bool> = vec![false; points.len()];
        let mut min_cost: Vec<i32> = vec![i32::MAX; points.len()];
        let mut total_cost = 0;
        min_cost[0] = 0;

        for i in 0..n {
            let min_idx = (0..n)
                .filter(|i| !visited[*i])
                .min_by_key(|x| min_cost[*x])
                .unwrap();
            visited[min_idx] = true;
            total_cost += min_cost[min_idx];
            (0..n).filter(|j| !visited[*j]).map(|j|{
                let cost = (points[min_idx][0] - points[j][0]).abs() + (points[min_idx][1] - points[j][1]).abs();
                min_cost[j] = min_cost[j].min(cost);
            }).for_each(|_|{});
        }

        total_cost
    }
}




// -------------------
use std::mem::swap;
struct UnionFindSet {
    parent: Vec<usize>,
    rank: Vec<usize>,
}
// let parent = vec![0usize; n];
impl crate::UnionFindSet {
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
    pub fn union(&mut self, index1: usize, index2: usize) {
        let mut p1 = self.find(index1);
        let mut p2 = self.find(index2);
        if self.rank[p1] < self.rank[p2] {
            swap(&mut p1, &mut p2);
        }
        self.parent[p1] = p2;
        self.rank[p1] += self.rank[p2];
    }
}

impl Solution {
    pub fn min_cost_connect_points_2(points: Vec<Vec<i32>>) -> i32 {
        let mut points = points;
        let n = points.len();
        let mut set = UnionFindSet::new(n);
        let mut edges: Vec<(usize, usize, usize)> = Vec::with_capacity(n * (n - 1) / 2);
        for i in 0..n {
            let point1 = &points[i];
            for j in i + 1..n {
                let point2 = &points[j];
                edges.push((
                    ((point1[0] - point2[0]).abs() + (point1[1] - point2[1]).abs()) as usize,
                    i,
                    j,
                ));
            }
        }
        edges.sort();
        let mut res = 0;
        for edge in edges {
            if set.find(edge.1) != set.find(edge.2) {
                set.union(edge.1, edge.2);
                // println!("{:?} {:?} {:?}", edge.0, edge.1, edge.2);
                res += edge.0 as i32;
            }
        }
        res
    }
}

// find: a != a.par ; a.par == find(a)
// union: a.par = find(b.par)
// find

fn main() {
    println!(
        "{:?}",
        Solution::min_cost_connect_points(vec![
            vec![0, 0],
            vec![2, 2],
            vec![3, 10],
            vec![5, 2],
            vec![7, 0]
        ])
    );
    println!(
        "{:?}",
        Solution::min_cost_connect_points(vec![vec![3, 12], vec![-2, 5], vec![-4, 1]])
    );
}

//
// Created by zhiya at 2025/5/16 16:59
//
