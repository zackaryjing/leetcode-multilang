// problem: https://leetcode.cn/problems/maximum-length-of-subarray-with-positive-product/
struct Solution;

use std::cmp::max;
impl Solution {
    pub fn get_max_len(nums: Vec<i32>) -> i32 {
        let mut res = 0i32;
        let mut pos = 0;
        let mut neg = 0;
        for i in nums {
            if i == 0 {
                pos = 0;
                neg = 0;
            } else if i > 0 {
                pos += 1;
                neg += if neg != 0 { 1 } else { 0 };
            } else {
                let temp = pos;
                pos = if neg > 0 { neg + 1 } else { 0 };
                neg = temp + 1;
            }
            res = max(res, pos);
        }
        res
    }
}

fn main() {
    println!("{:?} 4", Solution::get_max_len(vec![1, -2, -3, 4]));
    println!("{:?} 3", Solution::get_max_len(vec![0, 1, -2, -3, -4]));
    println!("{:?} 2", Solution::get_max_len(vec![-1, -2, -3, 0, 1]));
}

//
// Created by zhiya at 2025/4/27 18:26
//
