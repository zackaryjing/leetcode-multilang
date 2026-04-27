// problem: https://leetcode.cn/problems/count-asterisks/?envType=problem-list-v2&envId=FeuPdeiM
struct Solution;

impl Solution {
    pub fn count_asterisks(s: String) -> i32 {
        let mut lcnt = 0;
        let s = s.as_bytes();
        let mut res = 0;
        let n = s.len();
        for i in 0..n {
            if s[i] == b'*' && lcnt % 2 == 0 {
                res += 1;
            } else if s[i] == b'|' {
                lcnt += 1;
            }
        }
        res
    }
}

fn main() {
    println!("{:?}", Solution::count_asterisks("l|*e*et|c**o|*de|".to_string()));
}

//
// Created by jing at 2026-04-21 15:54
//
