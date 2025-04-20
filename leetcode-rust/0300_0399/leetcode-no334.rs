// problem: https://leetcode.cn/problems/increasing-triplet-subsequence/
struct Solution;

use std::cmp::{max, min};
impl Solution {
    // pass, perf result
    pub fn increasing_triplet(nums: Vec<i32>) -> bool {
        let mut min_num = nums[0];
        let mut min_mid = i32::MAX;
        for num in nums {
            if num > min_mid {
                return true;
            }
            if num > min_num {
                min_mid = min(num, min_mid);
            } else {
                min_num = num;
            }
        }
        false
    }
}

impl Solution {
    // pass, can perf
    pub fn increasing_triplet_2(nums: Vec<i32>) -> bool {
        let mut lower: Vec<bool> = vec![false; nums.len()];
        let mut min_num = nums[0];
        for (i, num) in nums.iter().enumerate() {
            lower[i] = if num > &min_num { true } else { false };
            min_num = min(*num, min_num);
        }
        let mut max_num = nums[nums.len() - 1];
        for (i, num) in nums.iter().enumerate().rev() {
            if num < &max_num && lower[i] {
                return true;
            }
            max_num = max(max_num, *num);
        }
        false
    }
}

fn main() {
    println!("{:?}", Solution::increasing_triplet(vec![5, 1, 6])); // true
    println!("{:?}", Solution::increasing_triplet(vec![2, 1, 5, 0, 4, 6])); // true
    println!("{:?}", Solution::increasing_triplet(vec![1, 2, 3, 4, 5])); // true
    println!("{:?}", Solution::increasing_triplet(vec![5, 4, 3, 2, 1])); // false
}

//
// Created by zhiya at 2025/4/18 13:57
//
