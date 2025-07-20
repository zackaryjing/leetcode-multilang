// problem: https://leetcode.cn/problems/find-the-k-th-character-in-string-game-i/description/
struct Solution;

impl Solution {
    pub fn kth_character(k: i32) -> char {
        (b'a' + ((k - 1).count_ones() as u8 % 26)) as char
    }
}

fn main() {
    println!("{:?}", Solution::kth_character(5));
    println!("{:?}", Solution::kth_character(10));
}

//
// Created by zhiya at 7/3/2025 11:50 PM
//