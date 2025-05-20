// problem: https://leetcode.cn/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/
struct Solution;

use std::cmp::max;
impl Solution {
    pub fn max_depth_after_split(seq: String) -> Vec<i32> {
        let seq = seq.as_bytes();
        let n = seq.len();
        let mut res = vec![0; n];
        let mut cur = 0;
        let mut mx = 0;
        for ch in seq {
            if *ch == b'(' {
                cur += 1;
            } else {
                cur -= 1;
            }
            mx = max(mx, cur);
        }
        cur = 0;
        let limit = mx / 2;
        for i in 0..n {
            if seq[i] == b'(' {
                cur += 1;
                if cur > limit {
                    res[i] = 1;
                }
            } else {
                cur -= 1;
                if cur >= limit {
                    res[i] = 1;
                }
            }
        }
        res
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::max_depth_after_split("(()())".to_string())
    );
    println!(
        "{:?}",
        Solution::max_depth_after_split("()(())()".to_string())
    );
}

//
// Created by zhiya at 2025/4/30 14:33
//
