// problem: https://leetcode.cn/problems/ways-to-split-array-into-good-subarrays/
struct Solution;

impl Solution {
    pub fn number_of_good_subarray_splits(nums: Vec<i32>) -> i32 {
        let mut gap = 1;
        let mut index = 0;
        let n = nums.len();
        while index < n && nums[index] != 1 {
            index += 1;
        }
        if index >= n {
            return 0;
        }
        
        let _mod = 1000_000_007;

        let mut res =1i64;
        for index in index..n {
            if nums[index] == 0 {
                gap += 1;
            } else {
                res *= gap;
                res %= _mod;
                gap = 1;
            }
        }
        res as i32
    }
}

fn main() {
    println!("{:?}", Solution::number_of_good_subarray_splits(vec![0,0]));
    println!("{:?}", Solution::number_of_good_subarray_splits(vec![0,1,0]));
    println!("{:?}", Solution::number_of_good_subarray_splits(vec![0,1,0,0,1]));
    println!("{:?}", Solution::number_of_good_subarray_splits(vec![0,1,0,0,1,0,0]));
}

//
// Created by zhiya at 2025/5/28 10:14
//