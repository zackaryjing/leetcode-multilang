// problem: https://leetcode.cn/problems/lucky-numbers-in-a-matrix/description/
struct Solution;

use std::cmp::max;
impl Solution {
    pub fn lucky_numbers(matrix: Vec<Vec<i32>>) -> Vec<i32> {
        let m = matrix[0].len();
        let n = matrix.len();
        let mut column_max = vec![-1; m];
        for j in 0..m {
            for i in 0..n {
                column_max[j] = max(column_max[j], matrix[i][j]);
            }
        }
        let mut res = vec![];
        for i in 0..n {
            let mut mn = i32::MAX;
            let mut pos = 0;
            for j in 0..m {
                if matrix[i][j] < mn {
                    mn = matrix[i][j];
                    pos = j;
                }
            }
            // println!("{:?} {:?}",mn,pos);
            if mn == column_max[pos] {
                res.push(mn);
            }
        }
        res
    }
}

fn main() {
    println!(
        "{:?} e:15",
        Solution::lucky_numbers(vec![vec![3, 7, 8], vec![9, 11, 13], vec![15, 16, 17]])
    );
    println!(
        "{:?} e:12",
        Solution::lucky_numbers(vec![
            vec![1, 10, 4, 2],
            vec![9, 3, 8, 7],
            vec![15, 16, 17, 12]
        ])
    );
    println!(
        "{:?} e:7",
        Solution::lucky_numbers(vec![vec![7, 8], vec![1, 2]])
    );
}

//
// Created by jing at 2025-09-07 14:37
//
