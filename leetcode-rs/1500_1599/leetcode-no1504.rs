use utils::vec_helper::print_matrix;

// problem: https://leetcode.cn/problems/count-submatrices-with-all-ones/
struct Solution;

use std::cmp::min;
impl Solution {
    pub fn num_submat(mat: Vec<Vec<i32>>) -> i32 {
        let m = mat[0].len();
        let n = mat.len();
        let mut cnt = vec![0; m];
        let mut res = 0;
        for i in 0..n {
            for j in 0..m {
                if mat[i][j] == 0 {
                    cnt[j] = 0;
                } else {
                    cnt[j] += 1;
                }
            }
            for j in 0..m {
                let mut smallest = cnt[j];
                for k in j..m {
                    smallest = min(cnt[k], smallest);
                    res += smallest;
                    if (smallest == 0) {
                        break;
                    }
                }
            }
        }
        res
    }
}

impl Solution {
    // [Pass] try to perf ...
    pub fn num_submat_2(mat: Vec<Vec<i32>>) -> i32 {
        let m = mat[0].len();
        let n = mat.len();
        let mut cnt = vec![vec![0; m]; m];
        let mut res = 0;
        for i in 0..n {
            for j in 0..m {
                if mat[i][j] == 1 {
                    cnt[j][j] += 1;
                } else {
                    cnt[j][j] = 0;
                }
                res += cnt[j][j];
            }
            for k in (1..m).rev() {
                for j in 0..k {
                    if cnt[j][j + (m - k) - 1] != 0 && cnt[j + 1][j + (m - k)] != 0 {
                        cnt[j][j + (m - k)] += 1;
                    } else {
                        cnt[j][j + (m - k)] = 0;
                    }
                    res += cnt[j][j + (m - k)];
                }
            }
            // print_matrix(&cnt);
            // println!();
        }
        res
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::num_submat(vec![vec![1, 0, 1], vec![1, 1, 0], vec![1, 1, 0]])
    );
    println!(
        "{:?}",
        Solution::num_submat(vec![vec![0, 1, 1, 0], vec![0, 1, 1, 1], vec![1, 1, 1, 0]])
    );
}

//
// Created by zhiya at 2025/5/27 20:42
//
