// problem:  https://leetcode.cn/problems/count-number-of-pairs-with-absolute-difference-k/?envType=problem-list-v2&envId=FeuPdeiM
struct Solution;

use std::collections::HashMap;
impl Solution {
    pub fn count_k_difference(nums: Vec<i32>, k: i32) -> i32 {
        let mut cnts = HashMap::new();
        for num in nums {
            *cnts.entry(num).or_insert(0) += 1;
        }
        let mut res = 0;
        for (num, cnt) in &cnts {
            res += cnt * (cnts.get(&(num + k))).unwrap_or(&0);
        }
        res
    }
}

fn main() {
    println!("{:?}", Solution::count_k_difference(vec![1, 2, 2, 1], 1));
}

//
// Created by jing at 2026-04-27 20:14
//
