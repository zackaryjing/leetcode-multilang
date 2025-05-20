// problem: https://leetcode.cn/problems/count-the-hidden-sequences/?envType=daily-question&envId=2025-04-21
struct Solution;

use std::cmp::{max, min};
impl Solution {
    pub fn number_of_arrays(differences: Vec<i32>, lower: i32, upper: i32) -> i32 {
        let (_, mx, mn) = differences
            .iter()
            .fold((0i64, 0i64, 0i64), |(s, mx, mn), &x| {
                let s = s + x as i64;
                (s, max(s, mx), min(mn, s))
            });
        // println!("{:?} {:?}", upper, lower);
        max((upper - lower) as i64 - (mx - mn) + 1, 0) as i32
    }
}

fn main() {
    println!("{:?}", Solution::number_of_arrays(vec![1, -3, 4], 1, 6));
    println!("{:?}", Solution::number_of_arrays(vec![-40], -46, 53));
}

//
// Created by zhiya at 2025/4/21 13:51
//
