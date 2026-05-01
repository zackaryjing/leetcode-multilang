// problem: https://leetcode.cn/problems/intersection-of-multiple-arrays/?envType=problem-list-v2&envId=FeuPdeiM
struct Solution;

use std::collections::{HashMap, HashSet};
impl Solution {
    pub fn intersection(nums: Vec<Vec<i32>>) -> Vec<i32> {
        let mut cnts = HashMap::new();
        let mut n = nums.len();
        let mut res = vec![];
        for list in nums {
            for num in list {
                *cnts.entry(num).or_insert(0) += 1;
            }
        }
        for (key, val) in cnts {
            if val == n {
                res.push(key);
            }
        }
        res.sort();
        res
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::intersection(vec![
            vec![3, 1, 2, 4, 5],
            vec![1, 2, 3, 4],
            vec![3, 4, 5, 6]
        ])
    );
}

//
// Created by jing at 2026-04-28 00:09
//
