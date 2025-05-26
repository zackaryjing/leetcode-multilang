// problem: https://leetcode.cn/problems/distance-between-bus-stops/
struct Solution;

use std::cmp::min;
use std::mem::swap;

// time spent 5:42
impl Solution {
    pub fn distance_between_bus_stops(
        distance: Vec<i32>,
        mut start: i32,
        mut destination: i32,
    ) -> i32 {
        if destination < start {
            swap(&mut destination, &mut start);
        }

        let tot: i32 = distance.iter().sum();
        let mut res = 0;
        for i in start..destination {
            res += distance[i as usize];
        }
        min(tot - res, res)
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::distance_between_bus_stops(vec![1, 2, 3, 4], 0, 1)
    );
    println!(
        "{:?}",
        Solution::distance_between_bus_stops(vec![1, 2, 3, 4], 0, 2)
    );
    println!(
        "{:?}",
        Solution::distance_between_bus_stops(vec![1, 2, 3, 4], 2, 0)
    );
    println!(
        "{:?}",
        Solution::distance_between_bus_stops(vec![1, 2, 3, 4], 0, 3)
    );
    println!(
        "{:?}",
        Solution::distance_between_bus_stops(vec![1, 2, 3, 4], 3, 0)
    );
}

//
// Created by zhiya at 2025/5/26 12:48
//
