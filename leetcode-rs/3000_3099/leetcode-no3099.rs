// problem: https://leetcode.cn/problems/harshad-number/
struct Solution;

impl Solution {
    pub fn sum_of_the_digits_of_harshad_number(x: i32) -> i32 {
        let mut sum = 0;
        let mut num = x;
        while num > 0 {
            sum += num % 10;
            num /= 10;
        }
        if x % sum == 0 { sum } else { -1 }
    }
}

fn main() {
    println!("{}", Solution::sum_of_the_digits_of_harshad_number(18));
    println!("{}", Solution::sum_of_the_digits_of_harshad_number(24));
}

//
// Created by ASUS at 2025/5/8 21:56
//
