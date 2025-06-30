// problem: https://leetcode.cn/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/
struct Solution;

const MOD: i32 = 1000_000_007;
use std::cmp::max;
impl Solution {
    pub fn combination(k: i64, n: i64) -> i64 {
        let k = max(k, n - k);
        let mut res: i64 = 1;
        for i in 1..=n - k {
            res *= k + i;
            res %= MOD as i64;
            let i_inv = Self::fpow(i, MOD - 2);
            res *= i_inv;
            res %= MOD as i64;
        }
        res
    }
    pub fn fpow(num: i64, mut n: i32) -> i64 {
        let mut temp = num;
        let mut res = 1;
        while n > 0 {
            if n & 1 == 1 {
                res *= temp;
                res %= MOD as i64;
            }
            temp *= temp;
            temp %= MOD as i64;
            n >>= 1;
        }
        res
    }
    pub fn number_of_ways(start_pos: i32, end_pos: i32, k: i32) -> i32 {
        let diff = (start_pos - end_pos).abs();
        if diff > k {
            return 0;
        }
        let numerator = diff + k;
        if numerator & 1 == 1 {
            return 0;
        }
        Self::combination(numerator as i64 / 2, k as i64) as i32
    }
}
fn main() {
    // println!("{:?}", Solution::number_of_ways(1, 2, 3));
    // println!("{:?}", Solution::number_of_ways(2, 5, 10));
    // println!("{:?}", Solution::number_of_ways(272, 270, 6));
    println!("{:?}", Solution::number_of_ways(989, 1000, 99));
}

//
// Created by zhiya at 6/29/2025 2:28 PM
//
