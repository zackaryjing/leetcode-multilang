// problem: https://leetcode.cn/problems/remove-trailing-zeros-from-a-string/?envType=problem-list-v2&envId=FeuPdeiM
struct Solution;

impl Solution {
    pub fn remove_trailing_zeros(num: String) -> String {
        let mut end = num.len();
        let num = num.as_bytes();
        for (index, c) in num.iter().enumerate().rev() {
            if *c != b'0' {
                end = index + 1;
                break;
            }
        }
        String::from_utf8(num[..end].to_vec()).unwrap()
    }
}

fn main() {
    println!("{:?}", Solution::remove_trailing_zeros("51230100".to_string()));
    println!("{:?}", Solution::remove_trailing_zeros("123".to_string()));
}

//
// Created by jing at 2026-04-29 01:07
//
