// problem: https://leetcode.cn/problems/count-number-of-bad-pairs/?envType=daily-question&envId=2025-04-18
struct Solution;

use std::collections::HashMap;
impl Solution {
    pub fn count_bad_pairs(nums: Vec<i32>) -> i64 {
        let mut level: HashMap<i32, i64> = HashMap::with_capacity(nums.len());
        let n = nums.len() as i64;
        let mut res = n * (n - 1) / 2;
        for (i, num) in nums.iter().enumerate() {
            let t = level.entry(num - i as i32).or_default();
            res -= *t;
            *t += 1;
        }
        res
    }
}

fn main() {
    println!("{:?}", Solution::count_bad_pairs(vec![4, 1, 3, 3]));
    println!("{:?}", Solution::count_bad_pairs(vec![1, 2, 3, 4, 5]));
}

//
// Created by zhiya at 2025/4/18 12:33
//
