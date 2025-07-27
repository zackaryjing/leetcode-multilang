// problem: https://leetcode.cn/problems/maximum-score-from-removing-substrings/?envType=daily-question&envId=2025-07-23

struct Solution;

use std::cmp::{max, min};
impl Solution {
    pub fn maximum_gain(s: String, mut x: i32, mut y: i32) -> i32 {
        let s = s.as_bytes();
        let n = s.len();
        let mut start = 0;
        let mut res = 0;
        let mut a = b'a';
        let mut b = b'b';
        if x < y {
            (a, b) = (b, a);
            (x, y) = (y, x);
        }
        for end in 0..=n {
            let mut letter = b'x';
            if end != n {
                letter = s[end];
            }
            if letter != b'a' && letter != b'b' {
                if end - start <= 1 {
                    start = end + 1;
                    continue;
                }
                let mut a_cnt = 0;
                let mut b_cnt = 0;
                for i in start..end {
                    if s[i] == a {
                        a_cnt += 1;
                    } else {
                        if a_cnt == 0 {
                            b_cnt += 1;
                        } else {
                            a_cnt -= 1;
                            res += x
                        }
                    }
                }
                res += min(a_cnt, b_cnt) * y;
                start = end + 1;
            }
        }
        res
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::maximum_gain("cdbcbbaaabab".to_string(), 4, 5)
    );
    //  Solution::maximum_gain("cdbcaabbbaba".to_string(), 4, 5)
}

//
// Created By Zackary At 2025/7/23 11:35
//
