// problem: https://leetcode.cn/problems/di-string-match/
struct Solution;

// 2:12
impl Solution {
    pub fn di_string_match(s: String) -> Vec<i32> {
        let s = s.as_bytes();
        let n = s.len();
        let mut res = Vec::with_capacity(n);
        let start = s.iter().filter(|&c| *c == b'D').count() as i32;
        let mut left = start - 1;
        let mut right = start + 1;
        res.push(start);
        for i in s {
            match *i {
                b'I' => {
                    res.push(right);
                    right += 1;
                }
                b'D' => {
                    res.push(left);
                    left -= 1;
                }
                _ => {}
            }
        }
        res
    }
}

fn main() {
    println!("{:?}", Solution::di_string_match("IDID".to_string()));
    println!("{:?}", Solution::di_string_match("IIII".to_string()));
    println!("{:?}", Solution::di_string_match("DDDD".to_string()));
}

//
// Created by zhiya at 2025/5/24 21:54
//
