// problem: https://leetcode.cn/problems/maximum-sum-with-exactly-k-elements/

struct Solution;

impl Solution {
    pub fn maximize_sum(nums: Vec<i32>, k: i32) -> i32 {
        let m = nums.iter().max().unwrap();
        (m + m + k - 1) * k / 2
    }
}

fn main() {
    println!("{:?}", Solution::maximize_sum(vec![1, 2, 3, 4, 5], 3));
    println!("{:?}", Solution::maximize_sum(vec![5, 5, 5], 2));
}

//
// Created By Zackary At 2025/7/11 11:49
//