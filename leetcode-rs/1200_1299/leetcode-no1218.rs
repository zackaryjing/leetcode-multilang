// problem: https://leetcode.cn/problems/longest-arithmetic-subsequence-of-given-difference/?envType=problem-list-v2&envId=3rBpGyas
struct Solution;

use std::cmp::{max, min};
use std::collections::HashMap;
impl Solution {
    pub fn longest_subsequence(arr: Vec<i32>, difference: i32) -> i32 {
        let mut res = 1;
        let mx = *arr.iter().max().unwrap() - min(0, difference);
        let mn = *arr.iter().min().unwrap() - max(0, difference);
        let mut cnts = vec![0; (mx - mn) as usize + 1];
        for num in arr {
            let mut val = max(1, cnts[(num - mn) as usize]);
            val = max(val, 1 + cnts[(num - difference - mn) as usize]);
            res = max(res, val);
            cnts[(num - mn) as usize] = val;
        }
        res
    }
}

impl Solution {
    pub fn longest_subsequence2(arr: Vec<i32>, difference: i32) -> i32 {
        let mut cnts: HashMap<i32, i32> = HashMap::new();
        let mut res = 1;
        for num in arr {
            let mut val = max(1, *cnts.entry(num).or_insert(0));
            val = max(val, 1 + *cnts.entry(num - difference).or_default());
            res = max(res, val);
            *cnts.get_mut(&num).unwrap() = val;
        }
        res
    }
}
fn main() {
    println!("{:?}", Solution::longest_subsequence(vec![1, 2, 3, 4], 1));
    println!("{:?}", Solution::longest_subsequence(vec![1, 3, 5, 7], 1));
    println!(
        "{:?}",
        Solution::longest_subsequence(vec![1, 5, 7, 8, 5, 3, 4, 2, 1], -2)
    );
}

//
// Created by ASUS at 2026-01-25 17:16
//
