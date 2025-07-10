// problem: https://leetcode.cn/problems/reschedule-meetings-for-maximum-free-time-ii/?envType=daily-question&envId=2025-07-10

struct Solution;

fn top3(nums: &Vec<i32>) -> (i32, i32, i32) {
    let (mut m1, mut m2, mut m3) = (0, 0, 0);
    for &num in nums {
        if num >= m1 {
            (m1, m2, m3) = (num, m1, m2);
        } else if num >= m2 {
            (m1, m2, m3) = (m1, num, m2);
        } else if num >= m3 {
            (m1, m2, m3) = (m1, m2, num);
        }
    }
    (m1, m2, m3)
}

use std::cmp::max;
impl Solution {
    pub fn max_free_time(event_time: i32, start_time: Vec<i32>, end_time: Vec<i32>) -> i32 {
        let n = start_time.len();
        let mut segments = Vec::new();
        segments.push(start_time[0]);
        for i in 1..n {
            segments.push(start_time[i] - end_time[i - 1]);
        }
        segments.push(event_time - end_time[n - 1]);
        if n < 2 {
            return segments.iter().sum();
        }
        let (m1, m2, m3) = top3(&segments);
        let mut res = 0;
        for j in 1..n + 1 {
            let margins = segments[j] + segments[j - 1];
            let mut sides = [segments[j], segments[j - 1]];
            sides.sort();
            res = max(res, margins);
            let event = end_time[j - 1] - start_time[j - 1];
            if sides[1] != m1 && event <= m1 || sides[0] != m2 && event <= m2 || event <= m3 {
                res = max(res, margins + event);
            }
        }
        res
    }
}

fn main() {
    println!("{:?} 2", Solution::max_free_time(5, vec![1, 3], vec![2, 5]));
    println!(
        "{:?} 7",
        Solution::max_free_time(10, vec![0, 7, 9], vec![1, 8, 10])
    );
    println!(
        "{:?} 6",
        Solution::max_free_time(10, vec![0, 3, 7, 9], vec![1, 4, 8, 10])
    );
    println!(
        "{:?} 10",
        Solution::max_free_time(58, vec![3, 10, 13, 14, 52], vec![4, 13, 14, 49, 58])
    );
}

//
// Created By Zackary At 2025/7/10 10:54
//