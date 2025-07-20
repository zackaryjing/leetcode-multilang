// problem: https://leetcode.cn/problems/longest-harmonious-subsequence/description/
struct Solution;

use std::cmp::max;
use std::collections::HashMap;
impl Solution {
    pub fn find_lhs(nums: Vec<i32>) -> i32 {
        let mut cnts: HashMap<i32, i32> = HashMap::new();
        for num in nums {
            *cnts.entry(num).or_default() += 1;
        }
        let mut res: i32 = 0;
        for num in &cnts {
            if let Some(T) = cnts.get(&(num.0 + 1)) {
                res = max(res, num.1 + T);
            }
        }
        res
    }
}

fn main() {
    println!("{:?}", Solution::find_lhs(vec![1, 3, 2, 2, 5, 2, 3, 7]));
    println!("{:?}", Solution::find_lhs(vec![1,1,1,1]));
}

//
// Created by ASUS at 6/30/2025 10:42 PM
//