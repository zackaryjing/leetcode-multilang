// problem: https://leetcode.cn/problems/substrings-of-size-three-with-distinct-characters/
struct Solution;

impl Solution {
    pub fn count_good_substrings(s: String) -> i32 {
        let n = s.len();
        let s = s.as_bytes();
        let mut i = 2;
        let mut res = 0;
        while i < n {
            if s[i - 2] == s[i - 1] || s[i] == s[i - 2] {
                i += 1;
                continue;
            }
            if s[i] != s[i - 1] {
                res += 1;
            } else {
                i += 1;
            }
            i += 1;
        }
        res
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::count_good_substrings("xyzzaz".to_string())
    );
    println!(
        "{:?}",
        Solution::count_good_substrings("aababcabc".to_string())
    );
}

//
// Created by jing at 2025-09-13 11:59
//
