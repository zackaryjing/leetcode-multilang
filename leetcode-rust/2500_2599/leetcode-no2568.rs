
// problem: https://leetcode.cn/problems/minimum-impossible-or/
struct Solution;

use std::collections::HashSet;
impl Solution {
    pub fn min_impossible_or(nums: Vec<i32>) -> i32 {
        let occur: HashSet<i32> = nums.into_iter().collect();
        (0..32).find(|&i| !occur.contains(&( 1 << i ))).map(|i| 1 << i).unwrap()
    }
}


impl Solution {
    // [Pass] Try to improve
    pub fn min_impossible_or_2(nums: Vec<i32>) -> i32 {
        let occur: HashSet<i32> = HashSet::from_iter(nums);
        for i in 0..32 {
            if !occur.contains(&(1 << i)) {
                return 1 << i;
            } 
        }
        0
    }
}

fn main() {
    println!("{:?}", Solution::min_impossible_or(vec![5, 3, 2]));
    println!("{:?}", Solution::min_impossible_or(vec![2, 1]));
}

//
// Created by zhiya at 2025/5/7 10:27
//
