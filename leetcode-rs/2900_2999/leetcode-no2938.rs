// problem: https://leetcode.cn/problems/separate-black-and-white-balls/
struct Solution;

impl Solution {
    pub fn minimum_steps(s: String) -> i64 {
        let mut res = 0;
        let mut temp_cnt = 0;
        for &c in s.as_bytes().iter().rev() {
            if c == b'0' {
                temp_cnt += 1;
            } else {
                res += temp_cnt;
            }
        }
        res
    }
}

fn main() {
    println!("{:?}", Solution::minimum_steps("100".to_string()));
    println!("{:?}", Solution::minimum_steps("100".to_string()));
}

//
// Created by jing at 2025-09-19 23:37
//
