// problem: https://leetcode.cn/problems/longest-unequal-adjacent-groups-subsequence-i/?envType=daily-question&envId=2025-05-15
struct Solution;

impl Solution {
    pub fn get_longest_subsequence(words: Vec<String>, groups: Vec<i32>) -> Vec<String> {
        let mut last = -1;
        let mut res: Vec<String> = Vec::with_capacity(100);
        for (index, word) in words.iter().enumerate() {
            if (groups[index] != last) {
                last = groups[index];
                res.push(word.clone());
            }
        }
        res
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::get_longest_subsequence(
            vec!["a".to_string(), "b".to_string(), "c".to_string()],
            vec![0, 0, 1]
        )
    );
}

//
// Created by zhiya at 2025/5/15 13:00
//
