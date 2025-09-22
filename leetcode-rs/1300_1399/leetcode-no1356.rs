// problem: https://leetcode.cn/problems/sort-integers-by-the-number-of-1-bits/description/
struct Solution;

impl Solution {
    pub fn sort_by_bits(mut arr: Vec<i32>) -> Vec<i32> {
        arr.sort_by_key(|&num| num.count_ones() * 10000 + num as u32);
        arr
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::sort_by_bits(vec![0, 1, 2, 3, 4, 5, 6, 7, 8])
    );
}

//
// Created by jing at 2025-09-12 20:35
//
