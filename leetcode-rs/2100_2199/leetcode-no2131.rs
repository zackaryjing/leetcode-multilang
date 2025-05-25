// problem: https://leetcode.cn/problems/longest-palindrome-by-concatenating-two-letter-words/?envType=daily-question&envId=2025-05-25
struct Solution;

use std::cmp::min;
use std::collections::{HashMap, HashSet};
impl Solution {
    pub fn longest_palindrome(words: Vec<String>) -> i32 {
        let mut pairs: HashMap<(u8, u8), i32> = HashMap::new();
        for word in words {
            let temp = word.as_bytes();
            *pairs.entry((temp[0], temp[1])).or_default() += 1;
        }
        let mut has_mid = false;
        let mut pair_cnt = 0;
        let mut vis: HashSet<(u8, u8)> = HashSet::new();
        for (key, val) in &pairs {
            if vis.contains(&key) {
                continue;
            }
            if key.1 == key.0 {
                if val & 1 == 1 {
                    has_mid = true;
                }
                pair_cnt += val / 2;
            } else {
                pair_cnt += min(val, pairs.get(&(key.1, key.0)).unwrap_or(&0));
            }
            vis.insert((key.1, key.0));
        }
        pair_cnt * 4 + if has_mid { 2 } else { 0 }
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::longest_palindrome(vec!["lc".to_string(), "cl".to_string(), "gg".to_string()])
    );
    println!(
        "{:?}",
        Solution::longest_palindrome(vec![
            "ab".to_string(),
            "ty".to_string(),
            "yt".to_string(),
            "lc".to_string(),
            "cl".to_string(),
            "ab".to_string()
        ])
    );
    println!(
        "{:?}",
        Solution::longest_palindrome(vec!["cc".to_string(), "ll".to_string(), "xx".to_string()])
    );
}

//
// Created by zhiya at 2025/5/25 18:18
//
