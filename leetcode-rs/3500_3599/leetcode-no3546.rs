// problem: https://leetcode.cn/problems/equal-sum-grid-partition-i/solutions/3673985/mei-ju-fen-ge-xian-de-wei-zhi-pythonjava-6y75/ 
struct Solution;

impl Solution {
    pub fn can_partition_grid(grid: Vec<Vec<i32>>) -> bool {
        let n = grid.len();
        let m = grid[0].len();
        let mut cur:i64 = 0;
        let mut row = vec![0; n];
        for i in 0..n {
            for j in 0..m {
                cur += grid[i][j] as i64;
            }
            row[i] = cur;
        }
        if cur & 1 == 1 {
            return false;
        }
        let half_total = cur / 2;
        for &r in &row {
            if r == half_total {
                return true;
            }
        }
        cur = 0;
        for j in 0..m {
            for i in 0..n {
                cur += grid[i][j] as i64;
            }
            if cur == half_total {
                return true;
            }
        }
        false
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::can_partition_grid(vec![vec![1, 4], vec![2, 3]])
    );
}

//
// Created by jing at 2025-09-29 22:35
//
