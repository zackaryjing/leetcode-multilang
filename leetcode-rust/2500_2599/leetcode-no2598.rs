use std::arch::x86_64::_mm256_blend_epi16;

// problem: https://leetcode.cn/problems/smallest-missing-non-negative-integer-after-operations/
struct Solution;

impl Solution {
    pub fn find_smallest_integer(nums: Vec<i32>, value: i32) -> i32 {
        let mut times = vec![0;value as usize];
        let offset = 10i32.pow(9) - (10i32.pow(9) % value) + value;
        for num in nums {
            times[((num + offset) % value) as usize] += 1;
        }
        let mut min_index = 0;
        let mut min_val = i32::MAX;
        for i in 0..value as usize {
            if min_val > times[i] {
                min_val = times[i];
                min_index = i;
            }
        }
        min_index as i32 + min_val * value
    }
}

fn main() {
    println!("{:?}", Solution::find_smallest_integer(vec![1,-10,7,13,6,8],5));
    println!("{:?}", Solution::find_smallest_integer(vec![1,-10,7,13,6,8],7));
}

//
// Created by zhiya at 2025/5/11 20:23
//