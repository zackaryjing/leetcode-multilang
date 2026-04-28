// problem: https://leetcode.cn/problems/merge-strings-alternately/
struct Solution;

use std::cmp::min;
impl Solution {
    pub fn merge_alternately(word1: String, word2: String) -> String {
        let word1 = word1.as_bytes();
        let word2 = word2.as_bytes();
        let n = word1.len();
        let m = word2.len();
        let mut res = vec![b'a'; n + m];
        let mut second = false;
        for i in 0..n + m {
            if (i / 2 >= n || i / 2 >= m) {
                second = true;
                break;
            }
            if i % 2 == 0 {
                res[i] = word1[i / 2];
            } else {
                res[i] = word2[i / 2];
            }
        }
        if second {
            let mn = min(m, n);
            if n > m {
                res[2 * mn..].copy_from_slice(&word1[mn..]);
            } else {
                res[2 * mn..].copy_from_slice(&word2[mn..]);
            }
        }
        String::from_utf8(res).unwrap()
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::merge_alternately("abc".to_string(), "pqr".to_string())
    );
}

//
// Created by jing at 2026-04-28 18:10
//
