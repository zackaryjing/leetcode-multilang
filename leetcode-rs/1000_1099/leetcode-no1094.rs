// problem: https://leetcode.cn/problems/car-pooling/

struct Solution;

use std::cmp::max;
impl Solution {
    pub fn car_pooling(trips: Vec<Vec<i32>>, capacity: i32) -> bool {
        let mut n = trips.iter().max_by(|a, b| a[2].cmp(&b[2])).unwrap()[2] as usize;
        let mut diff = vec![0; n + 2];
        for trip in trips {
            diff[trip[1] as usize] += trip[0];
            diff[trip[2] as usize] -= trip[0];
        }
        let mut cur = 0;
        let mut mcnt = 0;
        for i in 0..=n + 1 {
            cur += diff[i];
            mcnt = max(mcnt, cur);
        }
        mcnt <= capacity
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::car_pooling(vec![vec![2, 1, 5], vec![3, 5, 7]], 3)
    );
    println!(
        "{:?}",
        Solution::car_pooling(vec![vec![2, 1, 5], vec![3, 3, 7]], 4)
    );
    println!(
        "{:?}",
        Solution::car_pooling(vec![vec![2, 1, 5], vec![3, 3, 7]], 5)
    );
}

//
// Created By Zackary At 2025/7/11 11:02
//
