// problem: https://leetcode.cn/problems/wiggle-subsequence/
struct Solution;

use std::cmp::max;
use std::cmp::min;
use std::mem::swap;

impl Solution {
    pub fn wiggle_max_length(nums: Vec<i32>) -> i32 {
        let mut dp1 = nums[0]; // down
        let mut dp2 = nums[0]; // up
        let mut len1 = 1;
        let mut len2 = 1;
        let n = nums.len();
        for i in 1..n {
            let num = nums[i];
            let last =nums[i - 1];
            if last <= num && last < num {
                len1 = max(len1,len2 + 1);
            } else if last > num && last >= num {
                len2 = max(len2,len1 + 1);
            }
        }
        max(len1, len2)
    }
}

fn main() {
    println!(
        "{}",
        Solution::wiggle_max_length(vec![1, 17, 5, 10, 13, 15, 10, 5, 16, 8])
   );
    println!(
        "{}",
        Solution::wiggle_max_length(vec![1,2,3,4,5,6,7,8,9])
    );
}

//
// Created by ASUS at 2025/4/23 23:31
//
