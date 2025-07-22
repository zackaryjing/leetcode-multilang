// problem: https://leetcode.cn/problems/maximum-erasure-value/?envType=daily-question&envId=2025-07-22

struct Solution;

use std::cmp::max;
use std::collections::HashSet;

impl Solution {
    pub fn maximum_unique_subarray(nums: Vec<i32>) -> i32 {
        let mut left = 0usize;
        let mut right = 1usize;
        let mut cur = nums[0];
        let n = nums.len();
        let mut occur: HashSet<i32> = HashSet::from([nums[0]]);
        let mut res = nums[0];
        while right < n {
            let num = nums[right];
            cur += num;
            if occur.contains(&num) {
                while nums[left] != num {
                    cur -= nums[left];
                    occur.remove(&nums[left]);
                    left += 1;
                }
                cur -= num;
                left += 1;
                occur.remove(&num);
            }
            occur.insert(num);
            right += 1;
            res = max(res, cur);
        }
        res
    }
}

fn main() {
    println!(
        "{:?} e: 17",
        Solution::maximum_unique_subarray(vec![4, 2, 4, 5, 6]),
    );
    println!(
        "{:?} e: 8",
        Solution::maximum_unique_subarray(vec![5, 2, 1, 2, 5, 2, 1, 2, 5])
    );
    println!(
        "{:?} ",
        Solution::maximum_unique_subarray(vec![1, 1, 1, 1, 1, 1])
    );
    println!(
        "{:?} ",
        Solution::maximum_unique_subarray(vec![1, 2, 3, 4, 1, 1])
    );
}

//
// Created By Zackary At 2025/7/22 10:22
//
