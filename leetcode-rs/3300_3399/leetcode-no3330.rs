// problem:
struct Solution;

impl Solution {
    pub fn possible_string_count(word: String) -> i32 {
        let word = word.as_bytes();
        let n = word.len();
        let mut res = 1;
        let mut cnt = 0;
        for i in 1..n {
            if word[i] != word[i - 1] {
                res += cnt;
                cnt = 0;
            } else {
                cnt += 1;
            }
        }
        res += cnt;
        res
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::possible_string_count("abbcccc".to_string())
    );
    println!("{:?}", Solution::possible_string_count("abcd".to_string()));
    println!("{:?}", Solution::possible_string_count("aaaa".to_string()));
}

//
// Created by ASUS at 7/1/2025 11:13 PM
//

