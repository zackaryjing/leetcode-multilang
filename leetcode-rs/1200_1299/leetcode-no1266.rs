// problem: https://leetcode.cn/problems/minimum-time-visiting-all-points/
struct Solution;

use std::cmp::{max, min};
impl Solution {
    pub fn min_time_to_visit_all_points(points: Vec<Vec<i32>>) -> i32 {
        let n = points.len();
        let mut res = 0i32;
        for i in 1..n {
            let dx = (points[i][0] - points[i - 1][0]).abs();
            let dy = (points[i][1] - points[i - 1][1]).abs();
            res += max(dy, dx);
        }
        res
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::min_time_to_visit_all_points(vec![vec![1, 1], vec![3, 4], vec![-1, 0]])
    );
}

//
// Created by zhiya at 2025/4/23 14:35
//
