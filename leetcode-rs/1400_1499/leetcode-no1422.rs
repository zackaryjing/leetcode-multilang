// problem: https://leetcode.cn/problems/maximum-score-after-splitting-a-string/description/
struct Solution;

impl Solution {
    pub fn max_score(s: String) -> i32 {
        let s = s.as_bytes();
        let n = s.len();
        let zero_cnt = s.iter().filter(|&&c| c == b'0').count() as i32;
        let mut left_zero = if s[0] == b'0' { 1 } else { 0 };
        let mut res = 0i32;
        for i in 1..n {
            res = std::cmp::max(res, 2 * left_zero + n as i32 - zero_cnt - i as i32);
            if s[i] == b'0' {
                left_zero += 1;
            }
        }
        res
    }
}

fn main() {
    println!("{:?}", Solution::max_score("011101".to_string()));
    println!("{:?}", Solution::max_score("00111".to_string()));
    println!("{:?}", Solution::max_score("1111".to_string()));
}

//
// Created by jing at 2025-09-30 14:55
//
