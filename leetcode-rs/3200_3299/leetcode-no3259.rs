// problem: https://leetcode.cn/problems/maximum-energy-boost-from-two-drinks/
struct Solution;

use std::cmp::max;
impl Solution {
    pub fn max_energy_boost(energy_drink_a: Vec<i32>, energy_drink_b: Vec<i32>) -> i64 {
        let n = energy_drink_a.len();
        let (mut ba0, mut ba1, mut ba2) = (0, 0, 0);
        let (mut bb0, mut bb1, mut bb2) = (0, 0, 0);
        ba0 = energy_drink_a[0] as i64;
        bb0 = energy_drink_b[0] as i64;
        ba1 = ba0 + energy_drink_a[1] as i64;
        bb1 = bb0 + energy_drink_b[1] as i64;
        for i in 2..n {
            ba2 = energy_drink_a[i] as i64 + max(ba1, bb0);
            bb2 = energy_drink_b[i] as i64 + max(bb1, ba0);
            (ba0, ba1) = (ba1, ba2);
            (bb0, bb1) = (bb1, bb2);
        }
        max(ba2, bb2)
    }
}

impl Solution {
    // too slow
    pub fn max_energy_boost2(energy_drink_a: Vec<i32>, energy_drink_b: Vec<i32>) -> i64 {
        let n = energy_drink_a.len();
        let mut boosta = vec![0i64; n + 1];
        let mut boostb = vec![0i64; n + 1];
        let res = 0i64;
        boosta[1] = energy_drink_a[0] as i64;
        boostb[1] = energy_drink_b[0] as i64;
        for i in 1..n {
            boosta[i + 1] = energy_drink_a[i] as i64 + max(boosta[i], boostb[i - 1]);
            boostb[i + 1] = energy_drink_b[i] as i64 + max(boostb[i], boosta[i - 1]);
        }
        max(boosta[n], boostb[n])
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::max_energy_boost(vec![1, 3, 1], vec![3, 1, 1])
    );
    println!(
        "{:?}",
        Solution::max_energy_boost(vec![4, 1, 1], vec![1, 1, 3])
    );
}

//
// Created by jing at 2025-09-16 12:05
//
