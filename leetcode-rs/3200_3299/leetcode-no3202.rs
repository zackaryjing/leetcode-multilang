// problem: https://leetcode.cn/problems/find-the-maximum-length-of-valid-subsequence-ii/

struct Solution;

use std::cmp::max;
impl Solution {
    pub fn maximum_length(nums: Vec<i32>, k: i32) -> i32 {
        let k = k as usize;
        let nums: Vec<usize> = nums.iter().map(|&i| i as usize % k).collect();
        let mut res = 1;
        for s in 0..k {
            let mut rem = vec![0; k];
            for &num in &nums {
                rem[num] = max(rem[num], rem[((s + k) - num) % k] + 1);
                res = max(res, rem[num]);
            }
        }
        res
    }
}

fn main() {
    println!(
        "{:?} ex:4",
        Solution::maximum_length(vec![1, 4, 2, 3, 1, 4], 3)
    );
    println!(
        "{:?} ex:5",
        Solution::maximum_length(vec![1, 2, 3, 4, 5], 2)
    );
}

//
// Created By Zackary At 2025/7/18 14:13
//
