// problem: https://leetcode.cn/problems/minimum-operations-to-make-array-values-equal-to-k/?envType=daily-question&envId=2025-04-09
struct Solution;
use std::collections::BTreeSet;

impl Solution {
    pub fn min_operations(nums: Vec<i32>, k: i32) -> i32 {
        let nums: BTreeSet<i32> = nums.into_iter().collect();
        if let Some(&first) = nums.first() {
            if first < k {
                return -1;
            } else if first == k {
                return nums.len() as i32 - 1;
            } else {
                return nums.len() as i32;
            }
        }
        -1
    }
}

fn main() {
    println!("{}", Solution::min_operations(Vec::from([10, 8, 10, 8]), 7)); // 2
    println!("{}", Solution::min_operations(Vec::from([9, 7, 5, 3]), 1)); // 4
    println!("{}", Solution::min_operations(Vec::from([2, 1, 2]), 2)); // -1
}

//
// Created by ASUS at 2025/4/9 0:40
//
