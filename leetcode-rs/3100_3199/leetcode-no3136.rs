// problem: https://leetcode.cn/problems/valid-word/?envType=daily-question&envId=2025-07-15
struct Solution;

impl Solution {
    pub fn is_valid(word: String) -> bool {
        if word.len() < 3 {
            return false;
        }
        let mut has_vowel = false;
        let mut has_consonant = false;
        for letter in word.as_bytes() {
            match letter {
                b'0'..=b'9' => {}
                b'a' | b'e' | b'i' | b'o' | b'u' | b'A' | b'E' | b'I' | b'O' | b'U' => {
                    has_vowel = true
                }
                b'a'..=b'z' | b'A'..=b'Z' => has_consonant = true,
                _ => return false,
            }
        }
        has_consonant && has_vowel
    }
}

fn main() {
    println!("{:?}", Solution::is_valid("234Adas".to_string()));
    println!("{:?}", Solution::is_valid("b3".to_string()));
    println!("{:?}", Solution::is_valid("a3$e".to_string()));
}

//
// Created by zhiya at 7/15/2025 8:59 AM
//
