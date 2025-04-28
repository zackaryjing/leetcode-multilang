// problem: https://leetcode.cn/problems/find-minimum-time-to-reach-last-room-i/solutions/2975560/dijkstra-zui-duan-lu-pythonjavacgo-by-en-7nj3/
struct Solution;

use std::cmp::{Reverse, max, min};
use std::collections::{BinaryHeap, HashSet, VecDeque};
impl Solution {
    pub fn min_time_to_reach(move_time: Vec<Vec<i32>>) -> i32 {
        let mut to_expand: BinaryHeap<Reverse<(i32, (i32, i32))>> = BinaryHeap::new();
        let n = move_time.len() as i32;
        let m = move_time[0].len() as i32;
        let mut time = vec![vec![i32::MAX; m as usize]; n as usize];
        let mut in_expand = vec![vec![false; m as usize]; n as usize];
        time[0][0] = 0;
        in_expand[0][0] = true;
        to_expand.push(Reverse((0, (0, 0))));
        let directions: Vec<(i32, i32)> = vec![(1, 0), (0, 1), (-1, 0), (0, -1)];
        while !to_expand.is_empty() {
            let Reverse((val, (ci, cj))) = to_expand.pop().unwrap();
            if ci == n - 1 && cj == m - 1 {
                return val;
            }
            for (di, dj) in &directions {
                let (ni, nj) = (ci + di, cj + dj);
                if ni >= 0 && ni < n && nj >= 0 && nj < m {
                    let ni = ni as usize;
                    let nj = nj as usize;
                    if !in_expand[ni][nj] {
                        time[ni][nj] = max(val, move_time[ni][nj]) + (ci + cj) % 2 + 1;
                        to_expand.push(Reverse((time[ni][nj], (ni as i32, nj as i32))));
                        in_expand[ni][nj] = true;
                    }
                }
            }
        }
        time[(n - 1) as usize][(m - 1) as usize]
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::min_time_to_reach(vec![
            vec![108, 95, 41, 99, 10],
            vec![54, 149, 120, 17, 116],
            vec![100, 135, 139, 69, 112],
            vec![97, 20, 73, 124, 59],
            vec![87, 80, 72, 15, 104]
        ])
    );
    println!(
        "{:?}",
        Solution::min_time_to_reach(vec![
            vec![94, 79, 62, 27, 69, 84],
            vec![6, 32, 11, 82, 42, 30]
        ])
    );
    println!(
        "{:?}",
        Solution::min_time_to_reach(vec![vec![0, 4], vec![4, 4]])
    );
    println!(
        "{:?}",
        Solution::min_time_to_reach(vec![vec![0, 0, 0], vec![0, 0, 0]])
    );
    println!(
        "{:?}",
        Solution::min_time_to_reach(vec![vec![0, 1], vec![1, 2]])
    );

    println!(
        "{:?}",
        Solution::min_time_to_reach(vec![vec![0, 58], vec![27, 69]])
    );
}

//
// Created by zhiya at 2025/4/28 18:21
//
