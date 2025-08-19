// problem: https://leetcode.cn/problems/check-if-number-is-a-sum-of-powers-of-three/?envType=daily-question&envId=2025-08-14
struct Solution;

impl Solution {
    pub fn check_powers_of_three(mut n: i32) -> bool {
        while n > 0 {
            if n % 3 != 0 {
                n -= 1;
            }
            if n % 3 != 0 {
                return false;
            }
            n /= 3;
        }
        true
    }
}

fn main() {
    println!("{:?} e:true", Solution::check_powers_of_three(12));
    println!("{:?} e:true", Solution::check_powers_of_three(91));
    println!("{:?} e:false", Solution::check_powers_of_three(21));
}

//
// Created by zhiya at 8/14/2025 5:05 PM
//
