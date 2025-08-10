// problem: https://leetcode.cn/problems/reordered-power-of-2/?envType=daily-question&envId=2025-08-10
struct Solution;

use std::cmp::min;
impl Solution {
    pub fn reordered_power_of2(mut n: i32) -> bool {
        let k = min(n.ilog2() + 4,31);
        if n == 0 {
            return true;
        }
        let mut cnts = [0; 10];
        while n > 0 {
            cnts[n as usize % 10] += 1;
            n /= 10;
        }
        for i in 0..=k {
            let mut m = 1 << i;
            let mut cur = [0; 10];
            while m > 0 {
                cur[m as usize % 10] += 1;
                m /= 10;
            }
            let mut valid = true;
            for j in 0..10 {
                if cnts[j] != cur[j] {
                    valid = false;
                }
            }
            if valid {
                return true;
            }
        }
        false
    }
}

fn main() {
    println!("{:?} e:true", Solution::reordered_power_of2(1));
    println!("{:?} e:false", Solution::reordered_power_of2(10));
    println!("{:?} e:true", Solution::reordered_power_of2(46));
    println!("{:?} e:true", Solution::reordered_power_of2(16));
    println!("{:?} e:true", Solution::reordered_power_of2(125));
}

//
// Created by zhiya at 8/10/2025 11:58 PM
//
