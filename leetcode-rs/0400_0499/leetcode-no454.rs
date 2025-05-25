
// problem: https://leetcode.cn/problems/4sum-ii/
struct Solution;

// spend: 18:27
use std::collections::HashMap;
impl Solution {
    pub fn four_sum_count(
        nums1: Vec<i32>,
        nums2: Vec<i32>,
        nums3: Vec<i32>,
        nums4: Vec<i32>,
    ) -> i32 {
        let mut first: HashMap<i32, i32> = HashMap::new();
        for i in &nums1 {
            for j in &nums2 {
                *first.entry(i + j).or_default() += 1;
            }
        }

        let mut res = 0;
        for i in &nums3 {
            for j in &nums4 {
                res += *first.get(&( 0 - j - i )).unwrap_or(&0);
            }
        }

        res
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::four_sum_count(vec![1, 2], vec![-2, -1], vec![-1, 2], vec![0, 2])
    );
}

//
// Created by zhiya at 2025/5/25 21:30
//
