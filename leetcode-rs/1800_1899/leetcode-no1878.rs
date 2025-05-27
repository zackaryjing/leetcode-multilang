use utils::print_matrix;

// problem: https://leetcode.cn/problems/get-biggest-three-rhombus-sums-in-a-grid/
struct Solution;


// time spent: 2:07:20

use std::cmp::{max, min};
impl Solution {
    // [Pass] It works... but writing this hurt my soul.
    // well, actually,the performance is not that bad after I remove the BTreeSet part.
    // it's an old-fashioned way to get the top three largest numbers.
    pub fn get_biggest_three(grid: Vec<Vec<i32>>) -> Vec<i32> {
        let n = grid.len();
        let m = grid[0].len();
        let mut prefix_bl_tr = vec![vec![0; m]; n];
        let mut prefix_tl_br = vec![vec![0; m]; n];
        let mut max_val = 0;
        let mut max_val2 = 0;
        let mut max_val3 = 0;

        for i in 0..n {
            let mut last = 0;
            let mut last2 = 0;
            for j in 0..=min(i, m - 1) {
                let val = grid[i - j][j];
                if val > max_val {
                    max_val3 = max_val2;
                    max_val2 = max_val;
                    max_val = val;
                } else if val > max_val2 && val != max_val {
                    max_val3 = max_val2;
                    max_val2 = val;
                } else if val > max_val3 && val != max_val2 && val != max_val {
                    max_val3 = val;
                }

                last += grid[i - j][j];
                prefix_bl_tr[i - j][j] = last;
                last2 += grid[n - 1 - i + j][j];
                prefix_tl_br[n - 1 - i + j][j] = last2;
            }
        }

        for j in 1..m {
            let mut last = 0;
            let mut last2 = 0;
            for i in (max(0, j as i32 + n as i32 - m as i32) as usize..n).rev() {
                let val = grid[i][j + n - 1 - i];

                if val > max_val {
                    max_val3 = max_val2;
                    max_val2 = max_val;
                    max_val = val;
                } else if val > max_val2 && val != max_val {
                    max_val3 = max_val2;
                    max_val2 = val;
                } else if val > max_val3 && val != max_val2 && val != max_val {
                    max_val3 = val;
                }
                last += grid[i][j + n - 1 - i];
                prefix_bl_tr[i][j + n - 1 - i] = last;
                last2 += grid[n - 1 - i][j + n - 1 - i];
                prefix_tl_br[n - 1 - i][j + n - 1 - i] = last2;
            }
        }

        for length in (3..=min(m, n)).step_by(2) {
            for i in 0..=n - length {
                for j in 0..=m - length {
                    let l = (i + length / 2, j);
                    let r = (i + length / 2, j + length - 1);
                    let t = (i, j + length / 2);
                    let b = (i + length - 1, j + length / 2);
                    let mut val = 0;
                    val += prefix_bl_tr[t.0][t.1]
                        - if l.1 > 0 {
                            prefix_bl_tr[l.0 + 1][l.1 - 1]
                        } else {
                            0
                        };
                    val += prefix_bl_tr[r.0][r.1]
                        - if b.0 < n - 1 {
                            prefix_bl_tr[b.0 + 1][b.1 - 1]
                        } else {
                            0
                        };
                    val += prefix_tl_br[b.0][b.1]
                        - if l.1 > 0 {
                            prefix_tl_br[l.0 - 1][l.1 - 1]
                        } else {
                            0
                        };
                    val += prefix_tl_br[r.0][r.1]
                        - if t.0 > 0 {
                            prefix_tl_br[t.0 - 1][t.1 - 1]
                        } else {
                            0
                        };
                    val -= grid[l.0][l.1] + grid[b.0][b.1] + grid[t.0][t.1] + grid[r.0][r.1];

                    if val > max_val {
                        max_val3 = max_val2;
                        max_val2 = max_val;
                        max_val = val;
                    } else if val > max_val2 && val != max_val {
                        max_val3 = max_val2;
                        max_val2 = val;
                    } else if val > max_val3 && val != max_val2 && val != max_val {
                        max_val3 = val;
                    }
                }
            }
        }

        let mut res = vec![];

        if max_val != 0 {
            res.push(max_val);
        }
        if max_val2 != 0 {
            res.push(max_val2);
        }
        if max_val3 != 0 {
            res.push(max_val3);
        }
        res
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::get_biggest_three(vec![
            vec![3, 4, 5, 1, 3],
            vec![3, 3, 4, 2, 3],
            vec![20, 30, 200, 40, 10],
            vec![1, 5, 5, 4, 1],
            vec![4, 3, 2, 2, 5]
        ])
    );
    println!(
        "{:?}",
        Solution::get_biggest_three(vec![vec![1, 2, 3], vec![4, 5, 6], vec![7, 8, 9]])
    );
    println!("{:?}", Solution::get_biggest_three(vec![vec![7, 7, 7]]));
    println!(
        "{:?}",
        Solution::get_biggest_three(vec![
            vec![20, 17, 9, 13, 5, 2, 9, 1, 5],
            vec![14, 9, 9, 9, 16, 18, 3, 4, 12],
            vec![18, 15, 10, 20, 19, 20, 15, 12, 11],
            vec![19, 16, 19, 18, 8, 13, 15, 14, 11],
            vec![4, 19, 5, 2, 19, 17, 7, 2, 2]
        ])
    );
}

//
// Created by zhiya at 2025/5/27 21:42
//
