// problem: https://leetcode.cn/problems/first-completely-painted-row-or-column/description/
struct Solution;

use std::cmp::{max, min};
use std::collections::HashMap;
impl Solution {
    pub fn first_complete_index(arr: Vec<i32>, mut mat: Vec<Vec<i32>>) -> i32 {
        let (n, m) = (mat.len(), mat[0].len());
        let mut pos = vec![0; m * n + 1];
        (0..m * n).for_each(|i| {
            pos[arr[i] as usize] = i as i32;
        });
        min(
            (0..n)
                .map(|i| {
                    (0..m)
                        .map(|j| {
                            mat[i][j] = pos[mat[i][j] as usize];
                            mat[i][j]
                        })
                        .max()
                        .unwrap()
                })
                .min()
                .unwrap(),
            (0..m)
                .map(|j| (0..n).map(|i| mat[i][j]).max().unwrap())
                .min()
                .unwrap(),
        )
    }
}

impl Solution {
    // too slow
    pub fn first_complete_index_2(arr: Vec<i32>, mat: Vec<Vec<i32>>) -> i32 {
        let c = arr.len();
        let pos: HashMap<i32, usize> =
            HashMap::from_iter((0..c).into_iter().map(|index| (arr[index], index)));
        let n = mat.len();
        let m = mat[0].len();
        let mut res = usize::MAX;
        for i in 0..n {
            let mut last_pos = 0;
            for j in 0..m {
                last_pos = max(last_pos, pos[&mat[i][j]]);
            }
            res = min(res, last_pos);
        }
        for j in 0..m {
            let mut last_pos = 0;
            for i in 0..n {
                last_pos = max(last_pos, pos[&mat[i][j]]);
            }
            res = min(res, last_pos);
        }
        res as i32
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::first_complete_index(
            vec![2, 8, 7, 4, 1, 3, 5, 6, 9],
            vec![vec![3, 2, 5], vec![1, 4, 6], vec![8, 7, 9]]
        )
    );
    println!(
        "{:?}",
        Solution::first_complete_index(vec![1, 3, 4, 2], vec![vec![1, 4], vec![2, 3]])
    );
}

//
// Created by jing at 2025-09-16 16:32
//
