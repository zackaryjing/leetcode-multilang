// problem: https://leetcode.cn/problems/maximum-number-of-balloons/
struct Solution;

// time used 7:47
use std::cmp::min;
impl Solution {
    pub fn max_number_of_balloons(text: String) -> i32 {
        let text = text.as_bytes();
        let mut b_cnt = 0;
        let mut a_cnt = 0;
        let mut l_cnt = 0;
        let mut o_cnt = 0;
        let mut n_cnt = 0;
        for ch in text {
            match ch {
                &b'b' => {
                    b_cnt += 1;
                }
                &b'a' => {
                    a_cnt += 1;
                }
                &b'l' => {
                    l_cnt += 1;
                }
                &b'o' => {
                    o_cnt += 1;
                }
                &b'n' => {
                    n_cnt += 1;
                }
                _ => {}
            }
        }
        min(min(a_cnt, min(b_cnt, n_cnt)), min(l_cnt / 2, o_cnt / 2))
    }
}

fn main() {
    println!("{:?}", Solution::max_number_of_balloons("loonbalxballpoon".to_string()));
    println!("{:?}", Solution::max_number_of_balloons("nlaebolko".to_string()));
}

//
// Created by zhiya at 2025/5/26 13:46
//
