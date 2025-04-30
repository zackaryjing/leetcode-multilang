// problem: https://leetcode.cn/problems/count-subarrays-where-max-element-appears-at-least-k-times/?envType=daily-question&envId=2025-04-29
struct Solution;

impl Solution {
    pub fn count_subarrays(nums: Vec<i32>, k: i32) -> i64 {
        let m = nums.iter().max().unwrap();
        let mut res = 0i64;
        let mut left = 0usize;
        let mut right = 0usize;
        let mut cur = 0;
        let n = nums.len();
        while left <= right && right < n {
            cur += if nums[right] == *m { 1 } else { 0 };
            while cur >= k {
                let temp = left;
                while nums[left] != *m {
                    left += 1;
                }
                res += ((n - right) * (left - temp + 1)) as i64;
                cur -= if nums[left] == *m { 1 } else { 0 };
                left += 1;
            }
            right += 1;
        }
        res
    }
}

impl Solution {
    // [Pass] Can perf
    pub fn count_subarrays_2(nums: Vec<i32>, k: i32) -> i64 {
        let m = nums.iter().max().unwrap();
        let mut res = 0i64;
        let mut left = 0usize;
        let mut right = 0usize;
        let mut cur = 0;
        let n = nums.len();
        while left <= right && right < n {
            cur += if nums[right] == *m { 1 } else { 0 };
            while cur >= k {
                res += (n - right) as i64;
                cur -= if nums[left] == *m { 1 } else { 0 };
                left += 1;
            }
            right += 1;
        }
        res
    }
}

fn main() {
    println!("{:?}", Solution::count_subarrays(vec![1, 3, 2, 3, 3], 2));
}

//
// Created by zhiya at 2025/4/29 15:17
//
