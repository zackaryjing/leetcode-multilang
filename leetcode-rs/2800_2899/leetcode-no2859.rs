// problem: https://leetcode.cn/problems/sum-of-values-at-indices-with-k-set-bits/
struct Solution;

impl Solution {
    pub fn sum_indices_with_k_set_bits(nums: Vec<i32>, k: i32) -> i32 {
        (0..nums.len())
            .into_iter()
            .map(|a| {
                if a.count_ones() == k as u32 {
                    nums[a]
                } else {
                    0
                }
            })
            .sum()
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::sum_indices_with_k_set_bits(vec![5, 10, 1, 5, 2], 1)
    );
}

//
// Created by jing at 2025-09-22 20:15
//
