// problem: https://leetcode.cn/problems/count-the-number-of-ideal-arrays/?envType=daily-question&envId=2025-04-22
struct Solution;

static MOD: usize = 1_000_000_007;
static MAX_N: usize = 10_000;
static MAX_E: usize = 13;

fn exp() -> Vec<Vec<usize>> {
    let mut res = vec![vec![]; (MAX_N + 1)];
    for x in 2..res.len() {
        let mut t = x;
        let mut i = 2;
        while i * i <= t {
            let mut e = 0;
            while t % i == 0 {
                e += 1;
                t /= i;
            }
            if e != 0 {
                res[x].push(e);
            }
            i += 1
        }
        if t > 1 {
            res[x].push(1);
        }
    }
    res
}

use std::cmp::min;
fn combine() -> Vec<Vec<usize>> {
    let mut res = vec![vec![0; MAX_E + 1]; MAX_N + MAX_E];
    for i in 0..res.len() {
        res[i][0] = 1;
        for j in 1..min(i, MAX_E) + 1 {
            res[i][j] = (res[i - 1][j] + res[i - 1][j - 1]) % MOD;
        }
    }
    res
}

impl Solution {
    pub fn ideal_arrays(n: i32, max_value: i32) -> i32 {
        let mut ans = 0;
        let ex = exp();
        let com = combine();
        for x in 1..(max_value + 1) as usize {
            let mut res = 1;
            for e in ex[x].iter() {
                res = res * com[n as usize + e - 1][*e] % MOD;
            }
            ans += res;
        }
        (ans % MOD) as i32
    }
}

fn main() {
    println!("{:?}", Solution::ideal_arrays(2, 5));
}

//
// Created by zhiya at 2025/4/22 18:15
//
