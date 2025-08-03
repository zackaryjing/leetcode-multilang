// problem: https://leetcode.cn/problems/minimum-number-of-frogs-croaking/
struct Solution;

use std::cmp::max;
use std::usize;

impl Solution {
    pub fn min_number_of_frogs(croak_of_frogs: String) -> i32 {
        let croak_of_frogs = croak_of_frogs.as_bytes();
        let pos = |c: u8| -> usize {
            match c {
                b'c' => 0,
                b'r' => 1,
                b'o' => 2,
                b'a' => 3,
                b'k' => 4,
                _ => usize::MAX,
            }
        };
        let mut cnts = vec![0; 5];
        let mut res = 0;
        for &c in croak_of_frogs {
            let p = pos(c);
            if p != 0 && cnts[p - 1] <= cnts[p] {
                return -1;
            }
            cnts[p] += 1;
            res = max(res, cnts[p] - cnts[4]);
        }
        let t = cnts[0];
        if cnts.iter().any(|&i| i != t) {
            return -1;
        }
        res
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::min_number_of_frogs("croakcroak".to_string())
    );
    println!(
        "{:?}",
        Solution::min_number_of_frogs("crcoakroak".to_string())
    );
    println!(
        "{:?}",
        Solution::min_number_of_frogs("croakcrook".to_string())
    );
    println!(
        "{:?} e:",
        Solution::min_number_of_frogs("aoocrrackk".to_string())
    );
}

//
// Created by zhiya at 8/3/2025 5:17 PM
//
