// problem: https://leetcode.cn/problems/max-chunks-to-make-sorted/
struct Solution;

use std::cmp::max;
impl Solution {
    pub fn max_chunks_to_sorted(arr: Vec<i32>) -> i32 {
        let mut left = 0;
        let mut right = 0;
        let mut cnt = 0;
        for i in 0..arr.len() {
            right = max(right, arr[i]);
            if i as i32 == right {
                cnt += 1;
                right += 1;
            }
        }
        cnt
    }
}

fn main() {
    println!("{:?}", Solution::max_chunks_to_sorted(vec![4, 3, 2, 1, 0]));
    println!("{:?}", Solution::max_chunks_to_sorted(vec![1, 0, 2, 3, 4]));
}

//
// Created by ASUS at 2026-01-28 13:30
//
