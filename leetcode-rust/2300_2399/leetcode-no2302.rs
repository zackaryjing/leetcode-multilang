use std::arch::x86_64::_mm_clflush;

// problem: https://leetcode.cn/problems/count-subarrays-with-score-less-than-k/?envType=daily-question&envId=2025-04-28
struct Solution;

impl Solution {
    pub fn count_subarrays(nums: Vec<i32>, k: i64) -> i64 {
        let mut left = 0usize;
        let mut right = 0usize;
        let n = nums.len();
        let mut tot = 0i64;
        let mut msum = 0i64;
        while right < n && left <= right {
            msum += nums[right] as i64;
            right += 1;
            while msum * (right - left) as i64 >= k {
                tot += (n - right) as i64 + 1;
                msum -= nums[left] as i64;
                left += 1;
            }
        }
        (n * (n + 1) / 2) as i64 - tot
    }
}

fn main() {
    println!("{:?}", Solution::count_subarrays(vec![2, 1, 4, 3, 5], 10));
    println!("{:?}", Solution::count_subarrays(vec![1, 1, 1], 5));
}

//
// Created by zhiya at 2025/4/28 11:18
//
