use std::collections::VecDeque;
use utils::print_matrix;

// problem: https://leetcode.cn/problems/number-of-ways-to-paint-n-3-grid/
struct Solution;

impl Solution {
    // [Pass] can perf...
    pub fn num_of_ways(mut n: i32) -> i32 {
        let _mod = 1000_000_007;
        let mut aba = 6i64;
        let mut abc = 6i64;
        for i in 0..(n - 1) as usize {
            let new_aba = aba * 3 + abc * 2;
            let new_abc = 2 * aba + 2 * abc;
            aba = new_aba % _mod;
            abc = new_abc % _mod;
        }
        ((aba + abc) % _mod) as i32
    }
}

impl Solution {
    // [Pass] can perf...
    pub fn num_of_ways_2(mut n: i32) -> i32 {
        let _mod = 1000_000_007;
        let mut valid: Vec<(i32, i32, i32)> = Vec::new();
        for i in 0..3 {
            for j in 0..3 {
                for k in 0..3 {
                    if i != j && j != k {
                        valid.push((i, j, k));
                    }
                }
            }
        }

        let m = valid.len();
        let mut adjacent: Vec<Vec<i64>> = vec![vec![0; m]; m];
        for i in 0..m {
            for j in 0..m {
                if i != j {
                    if valid[i].0 != valid[j].0
                        && valid[i].1 != valid[j].1
                        && valid[i].2 != valid[j].2
                    {
                        adjacent[i][j] = 1;
                    }
                }
            }
        }

        // println!("m: {:?}", m);
        // print_matrix(&adjacent);

        let multi = |first: &Vec<Vec<i64>>, second: &Vec<Vec<i64>>| -> Vec<Vec<i64>> {
            let mut res = vec![vec![0; m]; m];
            for i in 0..m {
                for j in 0..m {
                    for k in 0..m {
                        // println!("{:?} {:?}",first[i][k] , second[k][j]);
                        res[i][j] += (first[i][k] * second[k][j]) % _mod;
                        res[i][j] %= _mod;
                    }
                }
            }
            res
        };

        let mut cur = vec![vec![0; m]; m];
        for i in 0..m {
            cur[i][i] = 1;
        }
        n = n - 1;
        while n > 0 {
            // println!("n: {:?}",n);
            if n & 1 == 1 {
                cur = multi(&adjacent, &cur);
            }
            adjacent = multi(&adjacent, &adjacent);
            n >>= 1;
        }
        let mut res = 0;
        for i in 0..m {
            for j in 0..m {
                res += cur[i][j] % _mod;
                res %= _mod;
            }
        }
        res as i32
    }
}

fn main() {
    println!("{:?}", Solution::num_of_ways(1));
    println!("{:?}", Solution::num_of_ways(5000));
}

//
// Created by zhiya at 2025/5/27 18:12
//
