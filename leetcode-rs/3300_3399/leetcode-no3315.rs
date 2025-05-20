// problem: https://leetcode.cn/problems/construct-the-minimum-bitwise-array-ii/
struct Solution;
use std::io::{self, Write};

impl Solution {
    pub fn min_bitwise_array(nums: Vec<i32>) -> Vec<i32> {
        let n = nums.len();
        let mut res = Vec::with_capacity(n);
        for i in nums {
            if i % 2 == 0 {
                res.push(-1);
            } else {
                res.push(i & !((i ^ (i + 1)) + 1) >> 2);
            }
        }
        res
    }
}

fn main() {
    println!("{:?}", Solution::min_bitwise_array(vec![2, 3, 5, 7]));
}

//
// Created by zhiya at 2025/4/27 19:33
//
