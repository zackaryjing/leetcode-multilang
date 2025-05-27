// problem: https://leetcode.cn/problems/divisible-and-non-divisible-sums-difference/?envType=daily-question&envId=2025-05-27
struct Solution;

impl Solution {
    pub fn difference_of_sums(n: i32, m: i32) -> i32 {
        let mut cur = 0;
        let mut k = m;
        while k <= n {
            cur += k;
            k += m;
        }
        let tot: i32 = (0..=n).sum();
        tot - 2 * cur
    }
}

fn main() {
    println!("{:?}", Solution::difference_of_sums(10, 3));
    println!("{:?}", Solution::difference_of_sums(5, 6));
    println!("{:?}", Solution::difference_of_sums(1, 1));
    println!("{:?}", Solution::difference_of_sums(1, 1));
}

//
// Created by zhiya at 2025/5/27 14:18
//
