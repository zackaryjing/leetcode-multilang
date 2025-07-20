// problem: https://leetcode.cn/problems/count-days-without-meetings/?envType=daily-question&envId=2025-07-11

struct Solution;

use std::cmp::max;
impl Solution {
    pub fn count_days(days: i32, mut meetings: Vec<Vec<i32>>) -> i32 {
        let offset = 1000_000_000;
        meetings.sort_by(|a, b| a[0].cmp(&b[0]));
        let mut res = 0;
        let mut last_end = 0;
        for meeting in &meetings {
            if meeting[0] <= last_end + 1 {
                last_end = max(last_end, meeting[1]);
            } else {
                res += meeting[0] - last_end - 1;
                last_end = meeting[1];
            }
        }
        res += days - last_end;
        res
    }
}

fn main() {
    println!(
        "{:?} 1",
        Solution::count_days(
            14,
            vec![
                vec![6, 11],
                vec![7, 13],
                vec![8, 9],
                vec![5, 8],
                vec![3, 13],
                vec![11, 13],
                vec![1, 3],
                vec![5, 10],
                vec![8, 13],
                vec![3, 9]
            ]
        )
    );
    println!(
        "{:?} 2",
        Solution::count_days(10, vec![vec![5, 7], vec![1, 3], vec![9, 10]])
    );
    println!(
        "{:?} 1",
        Solution::count_days(10, vec![vec![3, 7], vec![5, 7], vec![1, 3], vec![9, 10]])
    );
    println!(
        "{:?} 1",
        Solution::count_days(5, vec![vec![2, 4], vec![1, 3]])
    );
    println!("{:?} 0", Solution::count_days(6, vec![vec![1, 6]]));
}

//
// Created By Zackary At 2025/7/11 9:30
//
