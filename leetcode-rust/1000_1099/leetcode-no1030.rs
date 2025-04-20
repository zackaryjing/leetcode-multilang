// problem: https://leetcode.cn/problems/matrix-cells-in-distance-order/
struct Solution;

impl Solution {
    pub fn all_cells_dist_order_2(
        rows: i32,
        cols: i32,
        r_center: i32,
        c_center: i32,
    ) -> Vec<Vec<i32>> {
        let mut board = vec![vec![0, 0]; (rows * cols) as usize];
        for i in 0..rows {
            for j in 0..cols {
                board[(i * cols + j) as usize] = vec![i, j];
            }
        }
        board.sort_by(|a, b| {
            return ((a[0] - r_center).abs() + (a[1] - c_center).abs())
                .cmp(&((b[0] - r_center).abs() + (b[1] - c_center).abs()));
        });
        board
    }
}

// 来写个所谓的桶排序

use std::cmp::max;
impl Solution {
    pub fn all_cells_dist_order(
        rows: i32,
        cols: i32,
        r_center: i32,
        c_center: i32,
    ) -> Vec<Vec<i32>> {
        let max_dist = max(rows - r_center - 1, r_center) + max(cols - c_center - 1, c_center);
        let mut bucket: Vec<Vec<Vec<i32>>> = vec![vec![]; (max_dist + 1) as usize];
        for i in 0..rows {
            for j in 0..cols {
                bucket[((i - r_center).abs() + (j - c_center).abs()) as usize].push(vec![i, j]);
            }
        }
        let mut res: Vec<Vec<i32>> = Vec::with_capacity((rows * cols) as usize);
        let mut i = 0;
        for dis in bucket {
            res.extend(dis);
        }
        res
    }
}

fn main() {
    println!("{:?}", Solution::all_cells_dist_order(2, 3, 1, 2));
}

//
// Created by zhiya at 2025/4/17 21:12
//
