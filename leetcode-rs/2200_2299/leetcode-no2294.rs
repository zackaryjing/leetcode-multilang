// problem: https://leetcode.cn/problems/partition-array-such-that-maximum-difference-is-k/?envType=daily-question&envId=2025-06-19
struct Solution;

use std::collections::HashSet;
impl Solution {
    // [Pass] no need to calculate unique nums
    pub fn partition_array_2(mut nums: Vec<i32>, k: i32) -> i32 {
        let mut unique_nums: Vec<i32> = nums
            .into_iter()
            .collect::<HashSet<_>>()
            .into_iter()
            .collect();
        unique_nums.sort();
        let n = unique_nums.len();
        let mut last = unique_nums[0];
        let mut cnt = 1;
        for i in 1..n {
            if unique_nums[i] - last > k {
                cnt += 1;
                last = unique_nums[i];
            }
        }
        cnt
    }
}


impl Solution {
    // [Pass] much better
    pub fn partition_array(mut nums: Vec<i32>, k: i32) -> i32 {
        nums.sort();
        let n = nums.len();
        let mut last = nums[0];
        let mut cnt = 1;
        for i in 1..n {
            if nums[i] - last > k {
                cnt += 1;
                last = nums[i];
            }
        }
        cnt
    }
}


fn main() {
    println!("{:?}", Solution::partition_array(vec![3, 6, 1, 2, 5], 2));
    println!("{:?}", Solution::partition_array(vec![1, 2, 3], 1));
    println!("{:?}", Solution::partition_array(vec![2, 2, 4, 5], 0));
}

//
// Created by zhiya at 6/19/2025 12:01 PM
//
