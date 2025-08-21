// problem: https://leetcode.cn/problems/count-submatrices-with-all-ones/?envType=daily-question&envId=2025-08-21

struct Solution;

use std::cmp::min;
impl Solution {
    pub fn count_squares(matrix: Vec<Vec<i32>>) -> i32 {

        0
    }
}
impl Solution {
    pub fn count_squares_2(matrix: Vec<Vec<i32>>) -> i32 {
        let n = matrix.len();
        let m = matrix[0].len();
        let mut v_matrix = vec![vec![0; m]; n];
        let mut h_matrix = vec![vec![0; m]; n];

        for j in 0..m {
            v_matrix[0][j] = matrix[0][j];
            for i in 1..n {
                v_matrix[i][j] = if matrix[i][j] != 0 {
                    v_matrix[i - 1][j] + 1
                } else {
                    0
                };
            }
        }
        for i in 0..n {
            h_matrix[i][0] = matrix[i][0];
            for j in 1..m {
                h_matrix[i][j] = if matrix[i][j] != 0 {
                    h_matrix[i][j - 1] + 1
                } else {
                    0
                };
            }
        }

        // for line in &v_matrix {
        //     println!("{:?}", line);
        // }
        // println!();
        // for line in &h_matrix {
        //     println!("{:?}", line);
        // }

        let mut res = 0;

        for i in 0..n {
            for j in 0..m {
                if matrix[i][j] == 1 {
                    res += 1;
                    for k in 1..min(n - i, m - j) {
                        let ni = i + k;
                        let nj = j + k;
                        let k = k as i32;

                        if i == 0 {
                            if v_matrix[ni][nj] != k + 1 {
                                break;
                            }
                        } else {
                            if v_matrix[ni][nj] - v_matrix[i - 1][nj] != k + 1 {
                                break;
                            }
                        }

                        if j == 0 {
                            if h_matrix[ni][nj] != k + 1 {
                                break;
                            }
                        } else {
                            if j != 0 && h_matrix[ni][nj] - h_matrix[ni][j - 1] != k + 1 {
                                break;
                            }
                        }
                        println!("{:?} {:?}", (i, j), (ni, nj));
                        res += 1;
                    }
                }
            }
        }
        res
    }
}

fn main() {
    println!(
        "{:?} e:7",
        Solution::count_squares(vec![vec![1, 0, 1], vec![1, 1, 0], vec![1, 1, 0]])
    );
    println!(
        "{:?} e:15",
        Solution::count_squares(vec![vec![0, 1, 1, 1], vec![1, 1, 1, 1], vec![0, 1, 1, 1]])
    );
}

//
// Created By Zackary At 2025/8/21 15:56
//
