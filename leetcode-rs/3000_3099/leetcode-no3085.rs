// problem: https://leetcode.cn/problems/minimum-deletions-to-make-string-k-special/?envType=daily-question&envId=2025-06-21
struct Solution;

impl Solution {
    pub fn minimum_deletions(word: String, k: i32) -> i32 {
        let mut cnt: Vec<i32> = Vec::with_capacity(26);
        for ch in word.as_bytes() {
            cnt[(ch - b'a') as usize]+=1;
        }
        cnt.sort();
        cnt.iter().fold(0,|a,b|{return a});
        
        
        0
    }
}

fn main() {
    println!("{:?}", Solution::);
}

//
// Created by zhiya at 6/21/2025 11:07 AM
//l