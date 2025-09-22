// problem: https://leetcode.cn/problems/check-knight-tour-configuration/
struct Solution;

impl Solution {
    pub fn check_valid_grid(grid: Vec<Vec<i32>>) -> bool {
        let n = grid.len();
        if grid[0][0] != 0 {
            return false;
        }
        let mut pos: Vec<(i32, i32)> = vec![(0, 0); n * n];
        for i in 0..n {
            for j in 0..n {
                pos[grid[i][j] as usize] = (i as i32, j as i32);
            }
        }
        let mut valid = true;
        for i in 1..n * n {
            let diffi = (pos[i].0 - pos[i - 1].0).abs();
            let diffj = (pos[i].1 - pos[i - 1].1).abs();
            if !(diffi == 2 && diffj == 1 || diffi == 1 && diffj == 2) {
                valid = false;
                break;
            }
        }
        valid
    }
}

fn main() {
    println!(
        "{:?} e:false",
        Solution::check_valid_grid(vec![vec![0, 3, 6], vec![5, 8, 1], vec![2, 7, 4]])
    );
    println!(
        "{:?} e:true",
        Solution::check_valid_grid(vec![
            vec![0, 11, 16, 5, 20],
            vec![17, 4, 19, 10, 15],
            vec![12, 1, 8, 21, 6],
            vec![3, 18, 23, 14, 9],
            vec![24, 13, 2, 7, 22]
        ])
    );
}

//
// Created by jing at 2025-09-09 22:09
//