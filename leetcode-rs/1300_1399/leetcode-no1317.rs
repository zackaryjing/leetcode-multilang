// problem: https://leetcode.cn/problems/convert-integer-to-the-sum-of-two-no-zero-integers
struct Solution;

impl Solution {
    pub fn get_no_zero_integers(n: i32) -> Vec<i32> {
        let num = n.to_string().into_bytes();
        let mut a = 0;
        let mut b = 0;
        let mut cur = 0;
        for i in 0..num.len() {
            
        }
        vec![a as i32, b as i32]
    }
}

fn main() {
    println!("{:?}", Solution::get_no_zero_integers(1000));
    println!("{:?}", Solution::get_no_zero_integers(11));
    println!("{:?}", Solution::get_no_zero_integers(2));
}

//
// Created by jing at 2026-03-30 23:22
//
