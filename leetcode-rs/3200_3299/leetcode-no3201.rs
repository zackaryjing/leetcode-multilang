
// problem: https://leetcode.cn/problems/find-the-maximum-length-of-valid-subsequence-i/?envType=daily-question&envId=2025-07-16
struct Solution;

use std::cmp::max;
impl Solution {
    pub fn maximum_length(nums: Vec<i32>) -> i32 {
        let mut all_one = 0;
        let mut all_zero = 0;
        let mut zero_end = 0;
        let mut one_end = 0;
        for num in nums {
            if num % 2 == 0 {
                all_one += 1;
                zero_end = one_end + 1;
            } else {
                all_zero += 1;
                one_end = zero_end + 1;
            }
        }
        max(max(all_one, all_zero), max(zero_end, one_end))
    }
}

fn main() {
    println!("{:?}", Solution::maximum_length(vec![1, 2, 1, 1, 2, 1, 2]));
}

//
// Created by zhiya at 7/16/2025 1:02 PM
//
