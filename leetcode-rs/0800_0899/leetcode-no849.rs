// problem: https://leetcode.cn/problems/maximize-distance-to-closest-person/?envType=problem-list-v2&envId=3rBpGyas
struct Solution;

use std::cmp::{max};
impl Solution {
    pub fn max_dist_to_closest(seats: Vec<i32>) -> i32 {
        let mut res = 1;
        let mut last = -1;
        for i in 0..seats.len() {
            if seats[i] == 1 {
                if last == -1 {
                    res = max(res, i as i32 - 0);
                } else {
                    res = max(res, (i as i32 - last) >> 1);
                }
                last = i as i32;
            }
        }
        res = max(res, seats.len() as i32 - last - 1);
        res
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::max_dist_to_closest(vec![1, 0, 0, 0, 1, 0, 1])
    );
}

//
// Created by ASUS at 2026-01-27 21:59
//
