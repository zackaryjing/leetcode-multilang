// problem: https://leetcode.cn/problems/minimum-deletions-to-make-string-k-special/?envType=daily-question&envId=2025-06-21
struct Solution;

use std::cmp::min;
impl Solution {
    pub fn minimum_deletions(word: String, k: i32) -> i32 {
        let mut cnt: Vec<i32> = vec![0; 26];
        for ch in word.as_bytes() {
            cnt[(ch - b'a') as usize] += 1;
        }
        cnt.sort();
        let n = 26;
        let mut right = 0;
        let mut res = i32::MAX;
        let mut left_cost = 0;
        let mut left = 0;
        while left < n {
            let lowest = cnt[left];
            let mut right_cost = 0;
            for i in right..n {
                if cnt[i] > lowest + k {
                    right = i;
                    break;
                }
            }
            if right < 26 && cnt[right] <= lowest + k {
                right = 26;
            }
            if right > 0 {
                for j in right..n {
                    right_cost += cnt[j] - (lowest + k);
                }
            }
            res = min(res, left_cost + right_cost);
            let cur = cnt[left];
            while left < n && cur == cnt[left] {
                left_cost += cnt[left];
                left += 1;
            }
        }
        res
    }
}

fn main() {
    println!(
        "{:?}\n",
        Solution::minimum_deletions("aabcaba".to_string(), 0)
    );
    println!(
        "{:?}\n",
        Solution::minimum_deletions("dabdcbdcdcd".to_string(), 2)
    );
    println!(
        "{:?}\n",
        Solution::minimum_deletions("aaabaaa".to_string(), 2)
    );
}


//
// Created by zhiya at 6/21/2025 11:07 AM
//l