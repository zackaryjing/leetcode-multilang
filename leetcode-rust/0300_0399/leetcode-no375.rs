// problem: https://leetcode.cn/problems/guess-number-higher-or-lower-ii/
struct Solution;

use std::cmp::{max, min};
impl Solution {
    pub fn get_money_amount(n: i32) -> i32 {
        let mut cost = vec![i32::MAX; n as usize];
        let mut times = vec![0; n as usize];
        for i in 0..n {
            for j in 0..=i {
                let mut left_cost = 0;
                let mut right_cost: i32 = 0;
                let mut left_times = 0;
                let mut right_times = 0;
                if j > 0 {
                    left_cost = cost[j - 1];
                    left_times = times[j - 1];
                }
                if j < i - 1 {
                    right_cost = cost[i - j - 1] + times[i - j - 1] * (j + 1);
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

                if temp_cost + j + 1 < cost[i] {
                    cost[i] = temp_cost + j + 1;
                    times[i] = temp_times;
                }
                // cost[i] = min(max(left_cost, right_cost) + i, cost[j]);
            }
        }
        println!("{:?}", cost);
        cost[n - 1]
    }
}

fn main() {
    println!("{:?}", Solution::get_money_amount(10));
}

//
// Created by zhiya at 2025/4/20 20:18
//
