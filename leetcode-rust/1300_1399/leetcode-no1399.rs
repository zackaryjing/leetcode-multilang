// problem: https://leetcode.cn/problems/count-largest-group/?envType=daily-question&envId=2025-04-23
struct Solution;
use std::collections::{HashMap, hash_map};

use std::cmp::max;
impl Solution {
    pub fn count_largest_group(n: i32) -> i32 {
        let mut mm = 0i32;
        let mut times = vec![0; 40];
        for i in 1..=n {
            let s: usize = i
                .to_string()
                .chars()
                .map(|x| x.to_digit(10).unwrap() as usize)
                .sum();
            times[s] += 1;
            mm = max(mm, times[s]);
        }
        let res = times.iter().filter(|&&x| x == mm).count();
        res as i32
    }
}

fn main() {
    println!("{:?}", Solution::count_largest_group(13));
    println!("{:?}", Solution::count_largest_group(2));
}

//
// Created by zhiya at 2025/4/23 11:33
//
