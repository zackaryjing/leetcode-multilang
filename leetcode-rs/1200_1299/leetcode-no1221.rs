// problem: https://leetcode.cn/problems/split-a-string-in-balanced-strings/description/
struct Solution;

impl Solution {
    // 0 1 1 
    pub fn tribonacci(n: i32) -> i32 {
        let mut base = vec![0, 1, 1, 2];
        for i in 0..n - 2 {
            base[3] = base[2] + base[1] + base[0];
            base[0] = base[1];
            base[1] = base[2];
            base[2] = base[3];
        }
        match n {
            0 => { 0 }
            1 => { 1 }
            _ => { base[2] }
        }
    }
}

fn main() {
    println!("{:?}", Solution::tribonacci(0));
    println!("{:?}", Solution::tribonacci(1));
    println!("{:?}", Solution::tribonacci(2));
    println!("{:?}", Solution::tribonacci(3));
    println!("{:?}", Solution::tribonacci(4));
    println!("{:?}", Solution::tribonacci(5));
    println!("{:?}", Solution::tribonacci(25));
}

//
// Created by zhiya at 2025/5/24 22:24
//
