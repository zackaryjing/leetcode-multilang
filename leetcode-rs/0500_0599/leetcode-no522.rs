// problem: https://leetcode.cn/problems/longest-uncommon-subsequence-ii/
struct Solution;

use std::cmp::max;
impl Solution {
    pub fn find_lu_slength(mut strs: Vec<String>) -> i32 {
        let n = strs.len();
        let mut res = -1;
        for j in 0..n {
            let mut valid = true;
            let s2 = &strs[j];
            for i in 0..n {
                if (i == j) {
                    continue;
                }
                let s1 = &strs[i];
                if s1.len() < s2.len() || (res > s2.len() as i32) {
                    continue;
                } else {
                    let mut pos = 0;
                    let m = s1.len();
                    let mut found = true;
                    for k in 0..s2.len() {
                        while pos < m && s1.as_bytes()[pos] != s2.as_bytes()[k] {
                            pos += 1;
                        }
                        if pos == m {
                            found = false;
                        }
                        pos += 1;
                    }
                    if found {
                        valid = false;
                    }
                }
            }
            if valid {
                res = max(res, s2.len() as i32);
            }
        }
        res
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::find_lu_slength(vec!["aba".to_string(), "cdc".to_string(), "ee".to_string()])
    );
    println!(
        "{:?}",
        Solution::find_lu_slength(vec!["aaa".to_string(), "aa".to_string(), "aa".to_string()])
    );
    println!(
        "{:?}",
        Solution::find_lu_slength(vec!["aaa".to_string(), "aaa".to_string(), "aa".to_string()])
    );
    println!(
        "{:?}",
        Solution::find_lu_slength(vec![
            "abcabc".to_string(),
            "abcabc".to_string(),
            "abcabc".to_string(),
            "abc".to_string(),
            "abc".to_string(),
            "cca".to_string()
        ])
    );
}

//
// Created by jing at 2025-10-15 19:22
//
