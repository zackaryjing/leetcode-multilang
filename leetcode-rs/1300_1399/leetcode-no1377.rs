// problem: https://leetcode.cn/problems/frog-position-after-t-seconds/
struct Solution;

use std::collections::VecDeque;
impl Solution {
    pub fn frog_position(n: i32, edges: Vec<Vec<i32>>, t: i32, target: i32) -> f64 {
        let target = target as usize;
        let n = n as usize;
        let mut graph: Vec<Vec<usize>> = vec![vec![]; n + 1];
        for edge in edges {
            graph[edge[0] as usize].push(edge[1] as usize);
            graph[edge[1] as usize].push(edge[0] as usize);
        }
        let mut to_vis: VecDeque<usize> = VecDeque::new();
        to_vis.push_back(1);
        let mut dist: Vec<i32> = vec![-1; n + 1];
        let mut par: Vec<i32> = vec![-1; n + 1];
        dist[1] = 0;
        while !to_vis.is_empty() {
            let head = to_vis.pop_front().unwrap();
            let d = dist[head];
            for adjacent in &graph[head] {
                let pos = *adjacent;
                if dist[pos] < 0 {
                    to_vis.push_back(*adjacent);
                    dist[pos] = d + 1;
                    par[pos] = head as i32;
                }
            }
        }
        let mut cur = target;
        let mut res: f64 = 1.0;
        loop {
            if cur == 1 {
                break;
            }
            let p = par[cur] as usize;
            let c = graph[p].len() - if p == 1 { 0 } else { 1 };
            res *= 1.0 / c as f64;
            cur = p;
        }
        if dist[target] == t
            || dist[target] < t && graph[target].len() == 1 && target != 1
            || n == 1 && target == 1
        {
            res
        } else {
            0.0
        }
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::frog_position(
            7,
            vec![
                vec![1, 2],
                vec![1, 3],
                vec![1, 7],
                vec![2, 4],
                vec![2, 6],
                vec![3, 5]
            ],
            2,
            4
        )
    );
    println!(
        "{:?}",
        Solution::frog_position(
            7,
            vec![
                vec![1, 2],
                vec![1, 3],
                vec![1, 7],
                vec![2, 4],
                vec![2, 6],
                vec![3, 5]
            ],
            1,
            7
        )
    );
    println!(
        "{:?}",
        Solution::frog_position(
            7,
            vec![
                vec![1, 2],
                vec![1, 3],
                vec![1, 7],
                vec![2, 4],
                vec![2, 6],
                vec![3, 5]
            ],
            20,
            6
        )
    );
}

//
// Created by zhiya at 6/20/2025 11:07 PM
//
