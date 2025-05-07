// problem: https://leetcode.cn/problems/removing-minimum-number-of-magic-beans/
struct Solution;

use std::cmp::min;
impl Solution {
    pub fn minimum_removal(beans: Vec<i32>) -> i64 {
        let mut beans = beans;
        beans.sort();
        let n = beans.len();
        let suffix_sum: Vec<i64> = beans
            .iter()
            .rev()
            .copied()
            .scan(0, |state, x| {
                *state += x as i64;
                Some(*state)
            })
            .collect();
        let mut pos = 0;
        let mut res = i64::MAX;
        let mut prefix_sum = 0;
        while pos < n {
            let mut temp = pos;
            while temp + 1 < n && beans[temp + 1] == beans[pos] {
                temp += 1;
            }
            let mut second_part = 0;
            if temp < n - 1 {
                second_part =suffix_sum[n - temp - 2] - (n - temp - 1) as i64 * beans[pos] as i64; 
            }
            res = min(
                prefix_sum + second_part,
                res
            );
            prefix_sum += (temp - pos + 1) as i64 * beans[pos] as i64;
            pos = temp + 1;
        }
        res
    }
}

fn main() {
    println!("{:?}", Solution::minimum_removal(vec![4, 1, 6, 5]));
    println!("{:?}", Solution::minimum_removal(vec![2, 10, 3, 2]));
}

//
// Created by zhiya at 2025/5/6 20:56
//
