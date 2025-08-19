// problem: https://leetcode.cn/problems/maximum-difference-score-in-a-grid/
struct Solution;

use std::cmp::{max, min};
impl Solution {
    pub fn max_score(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let m = grid[0].len();
        let mut max_br = vec![vec![0; m]; n];
        let mut dummy = i32::MIN;
        for i in (0..n).rev() {
            for j in (0..m).rev() {
                let mut mx = grid[i][j];
                if i < n - 1 {
                    mx = max(mx, max_br[i + 1][j]);
                    dummy = max(dummy, grid[i + 1][j] - grid[i][j]);
                }
                if j < m - 1 {
                    mx = max(mx, max_br[i][j + 1]);
                    dummy = max(dummy, grid[i][j + 1] - grid[i][j]);
                }
                max_br[i][j] = mx;
            }
        }
        let mut min_tl = vec![i32::MAX; m];
        let mut res = i32::MIN;
        for i in 0..n {
            min_tl[0] = min(min_tl[0], grid[i][0]);
            res = max(res, max_br[i][0] - min_tl[0]);
            for j in 1..m {
                min_tl[j] = min(min(min_tl[j - 1], min_tl[j]), grid[i][j]);
                res = max(res, max_br[i][j] - min_tl[j]);
            }
        }
        if dummy < 0 { dummy } else { res }
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::max_score(vec![
            vec![9, 5, 7, 3],
            vec![8, 9, 6, 1],
            vec![6, 7, 14, 3],
            vec![2, 5, 3, 1]
        ])
    );
    println!(
        "{:?}",
        Solution::max_score(vec![vec![4, 3, 2], vec![3, 2, 1]])
    );
}

//
// Created by zhiya at 8/17/2025 3:15 PM
//
