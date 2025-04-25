// problem: https://leetcode.cn/problems/find-smallest-letter-greater-than-target/description/
struct Solution;

impl Solution {
    pub fn next_greatest_letter(letters: Vec<char>, target: char) -> char {
        let mut res = letters[0];
        for ch in letters {
            if ch > target {
                res = ch;
                break;
            }
        }
        res
    }
}

fn main() {
    println!(
        "{}",
        Solution::next_greatest_letter(vec!['c', 'f', 'j'], 'a')
    );
}

//
// Created by ASUS at 2025/4/23 23:20
//
