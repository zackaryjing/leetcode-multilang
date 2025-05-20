// problem: https://leetcode.cn/problems/occurrences-after-bigram/
struct Solution;

use std::collections::HashSet;
impl Solution {
    pub fn find_ocurrences(text: String, first: String, second: String) -> Vec<String> {
        let mut res: Vec<String> = vec![];
        let mut first_found = false;
        let mut second_found = false;
        for word in text.split_whitespace() {
            if second_found {
                res.push(String::from(word));
            }
            second_found = false;
            if first_found && word == second {
                second_found = true;
            }
            first_found = false;
            if word == first {
                first_found = true;
            }
        }
        res
        // res.iter().cloned().collect()
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::find_ocurrences(
            String::from("alice is a good girl she is a good student"),
            String::from("a"),
            "good".to_string()
        )
    );
    println!(
        "{:?}",
        Solution::find_ocurrences(
            "jkypmsxd jkypmsxd kcyxdfnoa jkypmsxd kcyxdfnoa jkypmsxd kcyxdfnoa kcyxdfnoa jkypmsxd kcyxdfnoa".to_string(),
            "kcyxdfnoa".to_string(),
            "jkypmsxd".to_string()
        )
    );
}

//
// Created by zhiya at 2025/4/23 13:55
//
