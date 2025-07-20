// problem: https://leetcode.cn/problems/the-time-when-the-network-becomes-idle/

struct Solution;

use std::cmp::max;
impl Solution {
    pub fn network_becomes_idle(edges: Vec<Vec<i32>>, patience: Vec<i32>) -> i32 {
        let n = patience.len();
        // let mut graph = vec![Vec::with_capacity(30); n]; // can improve performance
        let mut graph = vec![vec![]; n];

        for edge in edges {
            graph[edge[0] as usize].push(edge[1] as usize);
            graph[edge[1] as usize].push(edge[0] as usize);
        }

        let mut vis = vec![false; n];
        let mut to_vis = graph[0].clone();
        let mut dist = 1;
        let mut res = 0;
        vis[0] = true;
        while !to_vis.is_empty() {
            let mut nxt_vis = Vec::new();
            for i in 0..to_vis.len() {
                let cur = to_vis[i];
                if vis[cur] {
                    continue;
                }
                vis[cur] = true;
                let k = patience[cur];
                res = max(
                    res,
                    4 * dist
                        - if (2 * dist) % k == 0 {
                            k
                        } else {
                            (2 * dist) % k
                        },
                );
                for &adj in &graph[cur] {
                    if !vis[adj] {
                        nxt_vis.push(adj);
                    }
                }
            }
            to_vis = nxt_vis;
            dist += 1;
        }
        res + 1
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::network_becomes_idle(vec![vec![0, 1], vec![1, 2]], vec![0, 2, 1])
    );
    println!(
        "{:?}",
        Solution::network_becomes_idle(vec![vec![0, 1], vec![0, 2], vec![1, 2]], vec![0, 10, 10])
    );
}

//
// Created By Zackary At 2025/7/4 17:37
//
