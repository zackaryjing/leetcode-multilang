use std::cmp::min;

// problem: https://leetcode.cn/problems/find-greatest-common-divisor-of-array/?envType=problem-list-v2&envId=FeuPdeiM
struct Solution;

use std::cmp::{};
impl Solution {
    pub fn find_gcd(nums: Vec<i32>) -> i32 {
        let mut mn = *nums.iter().min().unwrap();
        let mut mx = *nums.iter().max().unwrap();
        while mn != 0 {
            let tmp = mn;
            mn = mx % mn;
            mx = tmp;
        }
        mx
    }
}

fn main() {
    println!("{:?}", Solution::find_gcd(vec![2,5,6,9,10]));
    println!("{:?}", Solution::find_gcd(vec![7,5,6,8,3]));
}

//
// Created by jing at 2026-04-27 19:19
//
