// problem: https://leetcode.cn/problems/check-if-there-is-a-valid-path-in-a-grid/
struct Solution;

impl Solution {
    pub fn has_valid_path(grid: Vec<Vec<i32>>) -> bool {
        struct Dfs<'a> {
            grid: <'a>&Vec<Vec<i32>>,
            m: usize,
            n: usize,
        }
        ;
        impl Dfs {
            pub fn check(self, i: usize, j: usize) -> bool {
                0 <= i && i < self.n && 0 <= j && j < self.m
            }
            pub fn new(grid: Vec<Vec<i32>>) -> Self {
                Self {
                    &grid,
                    m:grid[0].len(),
                    n:grid.len()
                }
            }
            pub fn dfs(self, i: usize, j: usize, from: usize) {
                // 0 8 16 24
                let mut nxtj = 0;
                let mut nxti = 0;
                match self.grid[i][j] as usize + (from << 3) {
                    1 => {
                        nxtj = j + 1;
                        nxti = i;
                        check(nxtj, nxti);
                    }
                    17 => {
                        nxtj = j - 1;
                        nxti = i;
                    }
                    10 => {
                        nxtj = j;
                        nxti = i + 1;
                    }
                    26 => {
                        nxtj = j;
                        nxti = i - 1;
                    }
                    3 => {
                        nxtj = j;
                        nxti = i + 1;
                    }
                    27 => {
                        nxtj = j - 1;
                        nxti = i;
                    }
                    20 => {
                        nxtj = j;
                        nxti = i + 1;
                    }
                    28 => {
                        nxtj = j + 1;
                        nxti = i;
                    }
                    5 => {
                        nxtj = j;
                        nxti = i - 1;
                    }
                    13 => {
                        nxtj = j - 1;
                        nxti = i;
                    }
                    14 => {
                        nxtj = j + 1;
                        nxti = i;
                    }
                    22 => {
                        nxtj = j;
                        nxti = i - 1;
                    }
                    _ => {}
                }
            }
        }

        false
    }
}

fn main() {
    println!("{:?}", Solution::);
}

//
// Created by ASUS at 6/30/2025 10:58 PM
//
