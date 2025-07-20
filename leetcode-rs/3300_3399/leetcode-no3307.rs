// problem: https://leetcode.cn/problems/find-the-k-th-character-in-string-game-ii/?envType=daily-question&envId=2025-07-04
struct Solution;

use std::cmp::min;
impl Solution {
    pub fn kth_character(mut k: i64, operations: Vec<i32>) -> char {
        let mut base = 1i64;
        let mut mask = 0i64;
        k -= 1;
        for i in 0..min(63, operations.len()) {
            mask += operations[i] as i64 * base;
            base <<= 1;
        }
        let times = (k & mask).count_ones();
        (b'a' + (times % 26) as u8) as char
    }
}

fn main() {
    println!("{:?}", Solution::kth_character(10, vec![0, 1, 0, 1]))
}

//
// Created by zhiya at 7/4/2025 8:31 PM
//
