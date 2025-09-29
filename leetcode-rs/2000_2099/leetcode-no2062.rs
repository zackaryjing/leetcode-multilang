// problem: https://leetcode.cn/problems/count-vowel-substrings-of-a-string/
struct Solution;

impl Solution {
    pub fn count_vowel_substrings(word: String) -> i32 {
        let cnt = [0;6];
        let word = word.as_bytes();
        let n = word.len();
        let mut res = 0;
        for i in  0..n {
            let mut index = 0;
            let mut is_vowel = false;
            match word[i] {
                b'a' => {index = 0;is_vowel = true},
                b'e' => {index = 1;is_vowel = true},
                b'i' => {index = 2;is_vowel = true},
                b'o' => {index = 3;is_vowel = true},
                b'u' => {index = 4;is_vowel = true},
                _ => index = 5
            }
            cnt[index] += 1;
            if is_vowel {
                for i in 0..5 {
                    if cnt[i] != 1 {
                        break;
                    }
                }
            }
        }


    }
}

fn main() {
    println!("{:?}", Solution::count_vowel_substirngs());
}

//
// Created by ASUS at 9/22/2025 7:10 PM
//