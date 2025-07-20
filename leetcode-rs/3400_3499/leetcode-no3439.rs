// problem: https://leetcode.cn/problems/reschedule-meetings-for-maximum-free-time-i/?envType=daily-question&envId=2025-07-09

struct Solution;

use std::cmp::max;
impl Solution {
    pub fn max_free_time(event_time: i32, k: i32, start_time: Vec<i32>, end_time: Vec<i32>) -> i32 {
        let k = k as usize;
        let n = end_time.len();
        let mut segments = Vec::with_capacity(k + 1);
        segments.push(start_time[0]);
        for i in 0..n - 1 {
            segments.push(start_time[i + 1] - end_time[i])
        }
        segments.push(event_time - end_time[n - 1]);

        let mut spare_time: i32 = segments[0..=k].iter().sum();
        let mut res = spare_time;
        for end in k + 1..=n {
            spare_time += segments[end];
            spare_time -= segments[end - k - 1];
            res = max(res, spare_time);
        }
        res
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::max_free_time(5, 2, vec![0, 1, 2, 3, 4], vec![1, 2, 3, 4, 5])
    );
    println!(
        "{:?}",
        Solution::max_free_time(10, 1, vec![0, 2, 9], vec![1, 4, 10])
    );
    println!(
        "{:?}",
        Solution::max_free_time(5, 1, vec![1, 3], vec![2, 5])
    );
    println!(
        "{:?}",
        Solution::max_free_time(99, 1, vec![7, 21, 25], vec![13, 25, 78], )
    );
}

//
// Created By Zackary At 2025/7/9 16:21
//