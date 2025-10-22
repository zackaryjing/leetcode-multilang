// problem: https://leetcode.cn/problems/count-vowel-substrings-of-a-string/
struct Solution;

impl Solution {
    pub fn count_vowel_substrings(word: String) -> i32 {
        let mut cnt = [0; 6];
        let word = word.as_bytes();
        let n = word.len();
        let mut res = 0;
        let n = word.len();
        let pos = |c: u8| match c {
            b'a' => 0,
            b'e' => 1,
            b'i' => 2,
            b'o' => 3,
            b'u' => 4,
            _ => 5,
        };
        let check = |count: &[i32; 6]| -> bool {
            for i in 0..5usize {
                if count[i] == 0 {
                    return false;
                }
            }
            return true;
        };
        for i in 0..n {
            for j in i..n {
                let p = pos(word[j]);
                if p == 5 {
                    break;
                }
                cnt[p] += 1;
                if check(&cnt) {
                    res += 1;
                }
            }
            cnt = [0, 0, 0, 0, 0, 0];
        }
        res
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::count_vowel_substrings("aeiouu".to_string())
    );
    println!(
        "{:?}",
        Solution::count_vowel_substrings("unicornarihan".to_string())
    );
    println!(
        "{:?}",
        Solution::count_vowel_substrings("cuaieuouac".to_string())
    );
}

//
// Created by ASUS at 9/22/2025 7:10 PM
//
