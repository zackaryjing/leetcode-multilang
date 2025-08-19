// problem: https://leetcode.cn/problems/maximum-69-number/?envType=daily-question&envId=2025-08-16
struct Solution;

impl Solution {
    pub fn maximum69_number(num: i32) -> i32 {
        for i in (0..10).rev() {
            if num / 10i32.pow(i) % 10 == 6 {
                return num + 3 * 10i32.pow(i);
            }
        }
        num
    }
}

fn main() {
    println!("{:?}", Solution::maximum69_number(9996));
    println!("{:?}", Solution::maximum69_number(9966));
}

//
// Created by zhiya at 8/16/2025 2:09 PM
//
