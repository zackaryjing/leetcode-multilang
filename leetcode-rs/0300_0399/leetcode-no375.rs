// problem: https://leetcode.cn/problems/guess-number-higher-or-lower-ii/
struct Solution;

use utils::vec_helper::print_matrix;

use std::cmp::{max, min};
impl Solution {
    // [Offical] stealing solution...
    pub fn get_money_amount(n: i32) -> i32 {
        let n = n as usize;
        let mut f = vec![vec![0i32; n + 1]; n + 1];
        for i in (1..n).rev() {
            for j in (i + 1..=n) {
                f[i][j] = j as i32 + f[i][j - 1];
                for k in i..j {
                    f[i][j] = min(f[i][j], k as i32 + max(f[i][k - 1], f[k + 1][j]))
                }
            }
        }
        f[1][n]
    }
}

impl Solution {
    // [Fatal] Doesn't work, I am terrible. Tired.
    pub fn get_money_amount_3(n: i32) -> i32 {
        let n = n as usize;
        let mut mcost = vec![i32::MAX; n + 1];
        let mut mtimes = vec![i32::MAX; n + 1];
        mcost[0] = 0;
        mtimes[0] = 0;
        mcost[1] = 0;
        mtimes[1] = 0;
        let mut costs = vec![vec![i32::MAX; n + 1]; n + 1];
        let mut times = vec![vec![0; n + 1]; n + 1];
        costs[0] = vec![0; n + 1];
        times[0] = vec![0; n + 1];
        costs[1] = vec![0; n + 1];
        times[1] = vec![0; n + 1];
        for i in 2..=n {
            for j in 1..=i {
                let left_cost = mcost[j - 1];
                let left_times = mtimes[j - 1];
                let mut right_cost = 0;
                let mut right_times = 0;
                if j < i {
                    for k in 1..=i - j {
                        let temp_val = costs[i - j][k] + times[i - j][k] * j as i32;
                        if right_cost == 0 {
                            right_cost = temp_val;
                        } else if right_cost >= temp_val {
                            right_cost = temp_val;
                            if right_times == 0 {
                                right_times = times[i - j][k];
                            } else {
                                right_times = min(times[i - j][k], right_times);
                            }
                        }
                    }
                }
                // right_cost = mcost[i - j] + times[i - j] * j
                // costs[i][j] = max(right_cost,left_cost) + j as i32;
                // times[i][j] =
                // println!(
                //     "i: {:?} j: {:?} left: {:?} right: {:?}",
                //     i, j, left_cost, right_cost
                // );
                if right_cost > left_cost {
                    costs[i][j] = right_cost + j as i32;
                    times[i][j] = right_times + 1;
                    mtimes[i] = right_times + 1;
                    mcost[i] = min(mcost[i], right_cost + j as i32);
                } else if left_cost > right_cost {
                    costs[i][j] = left_cost + j as i32;
                    times[i][j] = left_times + 1;

                    mtimes[i] = left_times + 1;
                    mcost[i] = min(mcost[i], left_cost + j as i32);
                } else {
                    costs[i][j] = left_cost + j as i32;
                    times[i][j] = max(left_times, right_times) + 1;

                    mtimes[i] = max(left_times, right_times) + 1;
                    mcost[i] = min(mcost[i], left_cost + j as i32);
                }
            }
        }

        // print_matrix(&costs);
        // print_matrix(&times);

        mcost[n]
    }
}

// 0, 1, 2, 4, 6, 8, 10, 12, 14, 16, 18, 21, 24, 27, 30, 34, 38, 42, 46, 49, 52, 55, 58, 61, 64, 67, 70, 73, 76,
// 0  1, 3 6 10 13 16 19

fn main() {
    // println!("{:?}", Solution::get_money_amount(1));
    // println!("{:?}", Solution::get_money_amount(2));
    println!("{:?}", Solution::get_money_amount(3));
    println!("{:?}", Solution::get_money_amount(4));
    println!("{:?}", Solution::get_money_amount(5));
    println!("{:?}", Solution::get_money_amount(6));
    println!("{:?}", Solution::get_money_amount(7));
    println!("{:?}", Solution::get_money_amount(8));
    println!("{:?}", Solution::get_money_amount(9));
    println!("{:?}", Solution::get_money_amount(10));
    println!("{:?}", Solution::get_money_amount(11));
    println!("{:?}", Solution::get_money_amount(12));
    println!("{:?}", Solution::get_money_amount(13));
    println!("{:?}", Solution::get_money_amount(14));
    println!("{:?}", Solution::get_money_amount(15));
    println!("{:?}", Solution::get_money_amount(16));
    println!("{:?}", Solution::get_money_amount(17));
    println!("{:?}", Solution::get_money_amount(18));
}

impl Solution {
    // [Fatal]
    pub fn get_money_amount_2(n: i32) -> i32 {
        let mut cost = vec![i32::MAX; n as usize];
        let mut times = vec![0; n as usize];
        cost[0] = 0;
        for i in 1..n as usize {
            // println!("handing: {:?}", i);
            for j in 0..=i {
                // println!("\tmid: {:?}", j);
                let mut left_cost = 0;
                let mut right_cost = 0;
                let mut left_times = 0;
                let mut right_times = 0;
                if j > 0 {
                    left_cost = cost[j - 1];
                    left_times = times[j - 1];
                }
                if j < i {
                    right_cost = cost[i - j - 1] + times[i - j - 1] * (j + 1) as i32;
                    right_times = times[i - j - 1];
                }

                let mut temp_cost = 0;
                let mut temp_times = 0;
                if left_cost < right_cost {
                    temp_cost = right_cost;
                    temp_times = right_times;
                } else if left_cost > right_cost {
                    temp_cost = left_cost;
                    temp_times = left_times;
                } else {
                    temp_cost = left_cost;
                    temp_times = max(left_times, right_times);
                }

                if temp_cost + j as i32 + 1 < cost[i] {
                    cost[i] = temp_cost + j as i32 + 1;
                    times[i] = temp_times + 1;
                }
                // cost[i] = min(max(left_cost, right_cost) + i, cost[j]);
            }
            // println!("\tchosen: {:?}", cost[i]);
        }
        println!("{:?}", cost);
        println!("{:?}", times);
        cost[n as usize - 1]
    }
}

//
// Created by zhiya at 2025/4/20 20:18
//
