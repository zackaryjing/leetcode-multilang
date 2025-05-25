// problem: https://leetcode.cn/problems/find-the-maximum-sum-of-node-values/?envType=daily-question&envId=2025-05-23
struct Solution;

use std::collections::HashMap;
use std::collections::VecDeque;
use std::env::temp_dir;

use std::cmp::max;
impl Solution {
    pub fn maximum_value_sum(nums: Vec<i32>, k: i32, edges: Vec<Vec<i32>>) -> i64 {
        let n = nums.len();
        let mut graph = vec![vec![]; n];
        for edge in edges {
            let u = edge[0];
            let v = edge[1];
            graph[v as usize].push(u as usize);
            graph[u as usize].push(v as usize);
        }

        struct Helper {
            graph: Vec<Vec<usize>>,
            nums: Vec<i32>,
            k: i32,
        }
        impl Helper {
            pub fn new(graph: Vec<Vec<usize>>, nums: Vec<i32>, k: i32) -> Self {
                Self { graph, nums, k }
            }
            pub fn dfs(&self, u: usize, fa: usize) -> (i64, i64) {
                let mut f0 = 0i64;
                let mut f1 = i64::MIN;
                for v in &self.graph[u] {
                    if *v != fa {
                        let (r0, r1) = self.dfs(*v, u);
                        let t = max(f1 + r0, f0 + r1);
                        f0 = max(f0 + r0, f1 + r1);
                        f1 = t;
                    }
                }
                (
                    max(
                        f0 + self.nums[u] as i64,
                        f1 + (self.nums[u] ^ self.k) as i64,
                    ),
                    max(
                        f1 + self.nums[u] as i64,
                        f0 + (self.nums[u] ^ self.k) as i64,
                    ),
                )
            }
        }
        let helper = Helper { graph, nums, k };
        helper.dfs(0, usize::MAX).0
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::maximum_value_sum(
            vec![7, 7, 7, 7, 7, 7],
            3,
            vec![vec![0, 1], vec![0, 2], vec![0, 3], vec![0, 4], vec![0, 5]]
        )
    );
}

//
// Created by zhiya at 2025/5/23 13:10
//
