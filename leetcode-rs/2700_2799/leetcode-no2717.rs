use std::ops::Index;

// problem: https//leetcode.cn/problems/semi-ordered-permutation/?envType=problem-list-v2&envId=FeuPdeiM:
struct Solution;

impl Solution {
    pub fn semi_ordered_permutation(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let a = nums.iter().position(|&x| x == 1).unwrap();
        let b = nums.iter().position(|&x| x == n as i32).unwrap();
        let res = (a + n - b - 1) as i32;
        if res >= n as i32 { res - 1 } else { res }
    }
}

fn main() {
    println!("{:?}", Solution::semi_ordered_permutation(vec![2, 1, 4, 3]));
    println!("{:?}", Solution::semi_ordered_permutation(vec![2, 4, 1, 3]));
    println!(
        "{:?}",
        Solution::semi_ordered_permutation(vec![1, 3, 4, 2, 5])
    );
}

//
// Created by jing at 2026-04-29 01:16
//
