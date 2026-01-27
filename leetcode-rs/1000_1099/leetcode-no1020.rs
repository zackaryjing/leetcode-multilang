// problem: https://leetcode.cn/problems/number-of-enclaves/
struct Solution;

impl Solution {
    pub fn num_enclaves(mut grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let m = grid[0].len();
        struct Dfs<'a> {
            grid: &'a mut Vec<Vec<i32>>,
            cnt: i32,
            n: usize,
            m: usize,
        }

        impl<'a> Dfs<'a> {
            pub fn new(grid: &'a mut Vec<Vec<i32>>, n: usize, m: usize) -> Self {
                Self {
                    grid,
                    cnt: 0i32,
                    n,
                    m,
                }
            }
            pub fn dfs(&mut self, x: i32, y: i32) {
                self.grid[x as usize][y as usize] = 0;
                self.cnt += 1;
                for (dx, dy) in [(0, 1), (1, 0), (0, -1), (-1, 0)] {
                    let nx = x + dx;
                    let ny = y + dy;
                    if 0 <= nx && nx < self.n as i32 && 0 <= ny && ny < self.m as i32 {
                        if self.grid[nx as usize][ny as usize] == 1 {
                            self.dfs(nx, ny);
                        }
                    }
                }
            }
        }
        let mut oneCnt = 0;
        for i in 0..n {
            for j in 0..m {
                oneCnt += grid[i][j];
            }
        }
        let mut tmp = Dfs::new(&mut grid, n, m);
        for i in 0..n {
            if tmp.grid[i][0] == 1 {
                tmp.dfs(i as i32, 0i32);
            }
            if tmp.grid[i][m - 1] == 1 {
                tmp.dfs(i as i32, m as i32 - 1);
            }
        }
        for j in 0..m {
            if tmp.grid[0][j] == 1 {
                tmp.dfs(0, j as i32);
            }
            if tmp.grid[n - 1][j] == 1 {
                tmp.dfs(n as i32 - 1, j as i32);
            }
        }
        oneCnt - tmp.cnt
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::num_enclaves(vec![
            vec![0, 0, 0, 0],
            vec![1, 0, 1, 0],
            vec![0, 1, 1, 0],
            vec![0, 0, 0, 0]
        ])
    )
}

//
// Created by ASUS at 7/1/2025 11:40 PM
//
