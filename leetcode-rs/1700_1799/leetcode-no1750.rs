// problem: https://leetcode.cn/problems/minimum-length-of-string-after-deleting-similar-ends/
struct Solution;

use std::cmp::max;
impl Solution {
    pub fn minimum_length(s: String) -> i32 {
        let s = s.as_bytes();
        let n = s.len();
        let mut left = 0;
        let mut right = n - 1;
        while left < right && s[left] == s[right] {
            let c = s[left];
            while left < n && s[left] == c {
                left += 1;
            }
            while right > 0 && s[right] == c {
                right -= 1;
            }
        }
        max(right as i32 - left as i32 + 1, 0)
    }
}

fn main() {
    println!("{:?} e:0", Solution::minimum_length("cabaabac".to_string()));
    println!("{:?} e:2", Solution::minimum_length("ca".to_string()));
}

//
// Created by jing at 2025-09-14 20:09
//
