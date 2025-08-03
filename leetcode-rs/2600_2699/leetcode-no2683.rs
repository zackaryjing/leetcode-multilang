// problem: https://leetcode.cn/problems/neighboring-bitwise-xor/?envType=daily-question&envId=2025-07-31
struct Solution;

impl Solution {
    pub fn does_valid_array_exist(derived: Vec<i32>) -> bool {
        let mut cur = 1;
        for i in derived {
            cur ^= i;
        }
        cur == 1
    }
}

fn main() {
    println!("{:?}", Solution::does_valid_array_exist(vec![1, 1, 0]));
    println!("{:?}", Solution::does_valid_array_exist(vec![1, 1]));
    println!("{:?}", Solution::does_valid_array_exist(vec![1, 0]));
}

//
// Created by ASUS at 8/2/2025 7:00 PM
//
