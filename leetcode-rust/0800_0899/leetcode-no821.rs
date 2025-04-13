use std::cmp::min;

// problem: https://leetcode.cn/problems/shortest-distance-to-a-character/
struct Solution;

impl Solution {
    pub fn shortest_to_char(s: String, c: char) -> Vec<i32> {
        let s = Vec::<u8>::from(s);
        let n = s.len();
        let mut res: Vec<i32> = vec![n as i32; n];
        let mut dist = n as i32;
        for i in 0..n {
            dist += 1;
            if s[i] == c as u8 {
                dist = 0
            }
            res[i] = min(res[i], dist);
        }
        dist = n as i32;
        for i in (0..n).rev() {
            dist += 1;
            if s[i] == c as u8 {
                dist = 0
            }
            res[i] = min(res[i], dist);
        }
        res
    }
}
fn main() {
    println!(
        "{:?}",
        Solution::shortest_to_char(String::from("loveleetcode"), 'e')
    );
}

//
// Created by ASUS at 2025/4/12 20:26
//
