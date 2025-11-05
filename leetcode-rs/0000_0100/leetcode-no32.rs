// problem: https://leetcode.cn/problems/longest-valid-parentheses/
struct Solution;

use utils::vec_helper::print_matrix;
use std::cmp::max;
impl Solution {
    pub fn longest_valid_parentheses(s: String) -> i32 {
        let mut res = 0;
        let s = s.as_bytes();
        let n = s.len();
        let mut left = 0;
        let mut right = 0;
        for i in 0..n {
            if s[i] == '(' as u8 {
                left += 1;
            } else if s[i] == ')' as u8 {
                right += 1;
            }
            if right > left {
                res = max(left * 2, res);
                left = 0;
                right = 0;
            } else if right == left {
                res = max(left * 2, res);
            }
        }
        if left <= right {
            res = max(res, left * 2);
        }
        left = 0;
        right = 0;
        for i in (0..n).rev() {
            if s[i] == '(' as u8 {
                left += 1;
            } else if s[i] == ')' as u8 {
                right += 1;
            }
            if left > right {
                res = max(res, right * 2);
                left = 0;
                right = 0;
            } else if left == right {
                res = max(res, right * 2);
            }
        }
        if right <= left {
            res = max(res, right * 2);
        }
        res
    }
}

impl Solution {
    // [Fatal] TLE
    pub fn longest_valid_parentheses_2(s: String) -> i32 {
        let s = s.as_bytes();
        let n = s.len();
        if n < 2 {
            return 0;
        }
        let mut res = 0;
        let mut dp = vec![vec![false; n]; n];
        for i in 0..n - 1 {
            if s[i] == '(' as u8 && s[i + 1] == ')' as u8 {
                dp[i][i + 1] = true;
                res = 2;
            }
        }
        // print_matrix(&dp);
        for j in (3..n).step_by(2) {
            for i in 0..n - j {
                if s[i] == '(' as u8 && s[i + j] == ')' as u8 {
                    dp[i][i + j] = dp[i + 1][i + j - 1];
                }
                if !dp[i][i + j] {
                    for k in i + 2..i + j {
                        if dp[i][k - 1] && dp[k][i + j] {
                            dp[i][i + j] = true;
                            break;
                        }
                    }
                }
                if dp[i][i + j] {
                    res = max(res, j + 1);
                }
            }
        }
        // print_matrix(&dp);
        res as i32
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::longest_valid_parentheses(")()(((())))(".to_string())
    );
    println!(
        "{:?}",
        Solution::longest_valid_parentheses(")()())".to_string())
    );
    println!(
        "{:?}",
        Solution::longest_valid_parentheses("(()".to_string())
    );
    println!("{:?}", Solution::longest_valid_parentheses("".to_string()));
}

//
// Created by zhiya at 2025/4/23 14:51
//
