// problem: https://leetcode.cn/problems/count-days-spent-together/description/
struct Solution;

use std::cmp::{max, min};
impl Solution {
    pub fn count_days_together(
        arrive_alice: String,
        leave_alice: String,
        arrive_bob: String,
        leave_bob: String,
    ) -> i32 {
        let mut days = vec![0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
        let days_accu: Vec<i32> = days
            .iter()
            .scan(0, |a, b| {
                *a += b;
                Some(*a)
            })
            .collect();
        let parse_time = |s: String| -> i32 {
            let temp: Vec<usize> = s.split('-').map(|t| t.parse::<usize>().unwrap()).collect();
            return days_accu[temp[0] - 1] + temp[1] as i32;
        };
        let astart = parse_time(arrive_alice);
        let aend = parse_time(leave_alice);
        let bstart = parse_time(arrive_bob);
        let bend = parse_time(leave_bob);
        max(
            min(
                min(aend - bstart + 1, bend - astart + 1),
                min(aend - astart + 1, bend - bstart + 1),
            ),
            0,
        )
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::count_days_together(
            "10-01".to_string(),
            "10-31".to_string(),
            "11-01".to_string(),
            "12-31".to_string()
        )
    );
    println!(
        "{:?}",
        Solution::count_days_together(
            "08-15".to_string(),
            "08-18".to_string(),
            "08-16".to_string(),
            "08-19".to_string()
        )
    );
    println!(
        "{:?}",
        Solution::count_days_together(
            "09-01".to_string(),
            "10-19".to_string(),
            "06-19".to_string(),
            "10-20".to_string()
        )
    );
}

//
// Created by jing at 2025-09-14 14:39
//
