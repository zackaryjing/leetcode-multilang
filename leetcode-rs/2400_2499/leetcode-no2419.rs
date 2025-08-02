// problem: https://leetcode.cn/problems/longest-subarray-with-maximum-bitwise-and/?envType=daily-question&envId=2025-07-30
struct Solution;

use std::cmp::max;
impl Solution {
    pub fn longest_subarray(nums: Vec<i32>) -> i32 {
        let m_num = *nums.iter().max().unwrap();
        let mut res = 1;
        let mut cur = 0;
        for &num in &nums {
            if num == m_num {
                cur += 1;
            } else {
                res = max(res, cur);
                cur = 0;
            }
        }
        res = max(res, cur);
        res
    }
}

fn main() {
    println!("{:?}", Solution::longest_subarray(vec![1, 2, 3, 3, 2, 2]));
    println!("{:?}", Solution::longest_subarray(vec![1, 2, 3, 4]));
}

//
// Created by zhiya at 7/30/2025 1:15 PM
//
