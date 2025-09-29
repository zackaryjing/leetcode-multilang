// problem: https://leetcode.cn/problems/three-divisors/
struct Solution;

impl Solution {
    pub fn is_three(n: i32) -> bool {
        let mut k = n.isqrt();
        let mut cnt = 0;
        if k * k == n {
            cnt += 1;
        }
        for i in 1..k {
            if n % i == 0 {
                cnt += 2;
            }
        }
        cnt == 3
    }
}

fn main() {
    println!("{:?}", Solution::is_three(2));
    println!("{:?}", Solution::is_three(4));
}

//
// Created by jing at 2025-09-29 23:39
//
