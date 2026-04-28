// problem: https://leetcode.cn/problems/largest-odd-number-in-string/
struct Solution;

impl Solution {
    pub fn largest_odd_number(num: String) -> String {
        let num = num.as_bytes();
        let mut end = 0;
        for (index, c) in num.iter().enumerate().rev() {
            // println!("{index}");
            if (c - b'0') % 2 == 1 {
                end = index + 1;
                break;
            }
        }
        String::from_utf8(num[..end].to_vec()).unwrap().to_string()
    }
}

fn main() {
    println!("{:?}", Solution::largest_odd_number("52".to_string()));
    println!("{:?}", Solution::largest_odd_number("4206".to_string()));
    println!("{:?}", Solution::largest_odd_number("35427".to_string()));
}

//
// Created by jing at 2026-04-28 17:54
//
