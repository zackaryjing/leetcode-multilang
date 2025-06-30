// problem: https://leetcode.cn/problems/find-subsequence-of-length-k-with-the-largest-sum/?envType=daily-question&envId=2025-06-28
struct Solution;

use std::cmp::Reverse;
use std::collections::BinaryHeap;
impl Solution {
    pub fn max_subsequence(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let mut res_q = BinaryHeap::new();
        let mut size = 0;
        for (index, num) in nums.iter().enumerate() {
            res_q.push(Reverse((num, index)));
            if size == k {
                res_q.pop();
            } else {
                size += 1;
            }
        }
        let mut res_p = Vec::from(res_q);
        res_p.sort_by(|Reverse(a), Reverse(b)| a.1.cmp(&b.1));
        let mut res: Vec<i32> = res_p
            .iter()
            .map(|Reverse(a)| {
                return *a.0;
            })
            .collect();
        res
    }
}

fn main() {
    println!("{:?}", Solution::max_subsequence(vec![2, 1, 3, 3], 2));
    println!("{:?}", Solution::max_subsequence(vec![-1, -2, 3, 4], 3));
}

//
// Created by ASUS at 6/28/2025 4:04 PM
//
