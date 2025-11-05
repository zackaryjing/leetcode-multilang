// problem: https://leetcode.cn/problems/maximum-odd-binary-number/
struct Solution;

impl Solution {
    pub fn maximum_odd_binary_number(s: String) -> String {
        let n = s.len();
        let z_cnt = s.as_bytes().into_iter().filter(|&&c| c == b'0').count();
        "1".repeat(n - z_cnt - 1) + &("0".repeat(z_cnt)) + "1"
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::maximum_odd_binary_number("1010101".to_string())
    );
}

//
// Created by jing at 2025-09-30 13:34
//
