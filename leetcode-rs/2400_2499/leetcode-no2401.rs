// problem: https://leetcode.cn/problems/longest-nice-subarray/
struct Solution;

use std::cmp::max;
impl Solution {
    pub fn longest_nice_subarray(nums: Vec<i32>) -> i32 {
        let mut left = 0;
        let mut res = 1;
        let mut cur = nums[0];
        for right in 1..nums.len() {
            while (nums[right] & cur) != 0 {
                cur ^= nums[left]; // remove left
                left += 1
            }
            cur |= nums[right]; // add right
            res = max(res, right - left + 1);
        }
        res as i32
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::longest_nice_subarray(vec![1, 3, 8, 48, 10])
    );
}

//
// Created by zhiya at 6/29/2025 4:36 PM
//
