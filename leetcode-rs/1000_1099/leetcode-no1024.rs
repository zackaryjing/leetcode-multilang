// problem: https://leetcode.cn/problems/video-stitching/
struct Solution;

use std::cmp::{Ordering, max};
impl Solution {
    pub fn video_stitching(clips: Vec<Vec<i32>>, time: i32) -> i32 {
        let mut clips = clips;
        clips.sort_by(|a: &Vec<i32>, b: &Vec<i32>| {
            let ord0 = a[0].cmp(&b[0]);
            if ord0 == Ordering::Equal {
                return a[1].cmp(&b[1]).reverse();
            } else {
                return ord0;
            }
        });
        let mut res = 0;
        let n = clips.len();
        let mut max_right = 0;
        let mut i = 0usize;
        while i < n {
            let mut nx_right = max_right;
            let mut found = false;
            while i < n {
                if clips[i][0] <= max_right {
                    nx_right = max(nx_right, clips[i][1]);
                    found = true;
                } else {
                    break;
                }
                i += 1;
            }
            if found {
                max_right = nx_right;
                res += 1;
                if max_right >= time {
                    return res;
                }
            } else {
                return -1;
            }
        }
        -1
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::video_stitching(
            vec![
                vec![0, 2],
                vec![4, 6],
                vec![8, 10],
                vec![1, 9],
                vec![1, 5],
                vec![5, 9]
            ],
            10
        )
    );
    println!(
        "{:?}",
        Solution::video_stitching(
            vec![
                vec![0, 1],
                vec![6, 8],
                vec![0, 2],
                vec![5, 6],
                vec![0, 4],
                vec![0, 3],
                vec![6, 7],
                vec![1, 3],
                vec![4, 7],
                vec![1, 4],
                vec![2, 5],
                vec![2, 6],
                vec![3, 4],
                vec![4, 5],
                vec![5, 7],
                vec![6, 9]
            ],
            9
        )
    );
}

//
// Created by zhiya at 2025/4/30 16:24
//
