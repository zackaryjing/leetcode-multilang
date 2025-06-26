// problem: https://leetcode.cn/problems/sort-the-matrix-diagonally/
struct Solution;

use std::cmp::{max, min};
impl Solution {
    pub fn diagonal_sort(mat: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut mat = mat;
        let n = mat.len();
        let m = mat[0].len();
        for j in 0..m {
            let mut temp: Vec<i32> = Vec::new();
            for i in 0..min(n, m - j) {
                temp.push(mat[i][j + i]);
            }
            temp.sort();
            for i in 0..min(n, m - j) {
                mat[i][j + i] = temp[i];
            }
        }
        for i in 1..n {
            let mut temp: Vec<i32> = Vec::new();
            for j in 0..min(n - i, m) {
                temp.push(mat[i + j][j]);
            }
            temp.sort();
            for j in 0..min(n - i,m) {
                mat[i + j][j] = temp[j];
            }
        }
        mat
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::diagonal_sort(vec![
            vec![12, 13, 14, 15],
            vec![8, 9, 10, 11],
            vec![4, 5, 6, 7]
        ])
    );
}

//
// Created by zhiya at 6/26/2025 11:53 PM
//