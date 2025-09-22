// problem: https://leetcode.cn/problems/maximum-number-of-coins-you-can-get/
struct Solution;

use std::collections::BinaryHeap;
impl Solution {
    // too_slow
    pub fn max_coins_4(mut piles: Vec<i32>) -> i32 {
        let mut piles = BinaryHeap::from_iter(piles);
        let mut cnt = 0;
        let m = piles.len() / 3;
        let mut res = 0;
        while cnt < m {
            piles.pop();
            res += piles.pop().unwrap();
            cnt += 1;
        }
        res
    }
}

impl Solution {
    // too_slow
    pub fn max_coins_2(mut piles: Vec<i32>) -> i32 {
        piles.sort_unstable();
        let mut res = 0;
        let n = piles.len();
        let m = n / 3;
        let mut index = 0;
        while (index < m) {
            res += piles[n - index * 2 - 2];
            index += 1;
        }
        res
    }
}

impl Solution {
    // too_slow
    pub fn max_coins_3(mut piles: Vec<i32>) -> i32 {
        piles.sort_unstable();
        let mut res = 0;
        let n = piles.len();
        let m = n / 3;
        for i in (m..n - 1).rev().step_by(2) {
            res += piles[i];
        }
        res
    }
}

impl Solution {
    // too_slow
    pub fn max_coins(mut piles: Vec<i32>) -> i32 {
        piles.sort_unstable();
        piles[piles.len() / 3..].iter().step_by(2).sum()
    }
}

fn main() {
    println!("{:?}", Solution::max_coins(vec![2, 4, 1, 2, 7, 8]));
    println!("{:?}", Solution::max_coins(vec![2, 4, 5]));
    println!("{:?}", Solution::max_coins(vec![9, 8, 7, 6, 5, 1, 2, 3, 4]));
}

//
// Created by jing at 2025-09-15 17:10
//
