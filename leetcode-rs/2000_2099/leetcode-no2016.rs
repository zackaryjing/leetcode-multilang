// problem: https://leetcode.cn/problems/maximum-difference-between-increasing-elements/?envType=daily-question&envId=2025-06-16
struct Solution;

use std::cmp::{max, min};
impl Solution {
    pub fn maximum_difference(nums: Vec<i32>) -> i32 {
        let mut min_num = i32::MAX;
        let mut res = -1;
        nums.iter().fold(i32::MAX, |a, &b| {
            res = res.max(if a == b { -1 } else { b - a });
            return min(a, b);
        });
        res
    }
}

impl Solution {
    pub fn maximum_difference_2(nums: Vec<i32>) -> i32 {
        let mut min_num = i32::MAX;
        let mut res = -1;
        for num in nums {
            let temp = num - min_num;
            if temp != 0 {
                res = max(res, temp);
            }
            min_num = min(min_num, num);
        }
        res
    }
}

fn main() {
    println!("{:?}", Solution::maximum_difference(vec![7, 1, 5, 4]));
    println!("{:?}", Solution::maximum_difference(vec![9, 4, 3, 2]));
}

//
// Created by zhiya at 6/16/2025 1:55 PM
//
