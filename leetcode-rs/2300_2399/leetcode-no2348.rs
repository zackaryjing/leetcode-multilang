// problem: https://leetcode.cn/problems/number-of-zero-filled-subarrays/?envType=daily-question&envId=2025-08-19
struct Solution;

impl Solution {
    pub fn zero_filled_subarray(nums: Vec<i32>) -> i64 {
        let mut zc = 0;
        let mut res = 0;
        for i in nums {
            if i == 0 {
                zc += 1;
            } else {
                res += zc * (zc + 1) / 2;
                zc = 0;
            }
        }
        res += zc * (zc + 1) / 2;
        res
    }
}

fn main() {
    println!(
        "{:?} e:6",
        Solution::zero_filled_subarray(vec![1, 3, 0, 0, 2, 0, 0, 4])
    );
    println!(
        "{:?} e:9",
        Solution::zero_filled_subarray(vec![0, 0, 0, 2, 0, 0])
    );
}

//
// Created by zhiya at 8/19/2025 10:37 PM
//
