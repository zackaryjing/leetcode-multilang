// problem: https://leetcode.cn/problems/check-if-there-is-a-valid-path-in-a-grid/
struct Solution;

impl Solution {
    // [Pass] Performance bad
    pub fn has_valid_path_2(grid: Vec<Vec<i32>>) -> bool {
        struct Dfs<'a> {
            grid: &'a Vec<Vec<i32>>,
            m: usize,
            n: usize,
            valid: bool,
            vis: Vec<Vec<bool>>,
        };
        impl<'a> Dfs<'a> {
            pub fn check(&self, i: usize, j: usize, t: usize) -> bool {
                match t {
                    0 => j > 0,
                    1 => i > 0,
                    2 => j + 1 < self.m,
                    3 => i + 1 < self.n,
                    _ => false,
                }
            }
            pub fn new(grid: &'a Vec<Vec<i32>>) -> Self {
                Self {
                    grid: &grid,
                    m: grid[0].len(),
                    n: grid.len(),
                    valid: false,
                    vis: vec![vec![false; grid[0].len()]; grid.len()],
                }
            }
            pub fn reset_vis(&mut self) {
                self.vis = vec![vec![false; self.m]; self.n]
            }
            pub fn dfs(&mut self, i: usize, j: usize, from: usize) {
                let origins: Vec<(usize, usize)> =
                    vec![(0, 2), (1, 3), (0, 3), (2, 3), (0, 1), (2, 1)];
                let mut nxt = 0;
                let origin = origins[self.grid[i][j] as usize - 1];
                if self.vis[i][j] {
                    return;
                }
                self.vis[i][j] = true;

                if from == origin.0 {
                    nxt = origin.1
                } else if from == origin.1 {
                    nxt = origin.0
                } else {
                    return;
                }
                if i == self.n - 1 && j == self.m - 1 {
                    self.valid = true;
                    return;
                }
                let diff: Vec<(i32, i32)> = vec![(0, -1), (-1, 0), (0, 1), (1, 0)];
                if self.check(i, j, nxt) {
                    self.dfs(
                        (i as i32 + diff[nxt].0) as usize,
                        (j as i32 + diff[nxt].1) as usize,
                        (nxt + 2) % 4,
                    );
                }
            }
        }
        let mut d = Dfs::new(&grid);
        for k in 0..4 {
            d.dfs(0, 0, k);
            if d.valid {
                return true;
            }
            d.reset_vis();
        }
        false
    }
}

impl Solution {
    pub fn has_valid_path(grid: Vec<Vec<i32>>) -> bool {
        let m = grid[0].len();
        let n = grid.len();
        let check = |i: usize, j: usize, t: usize| -> bool {
            match t {
                0 => j > 0,
                1 => i > 0,
                2 => j + 1 < m,
                3 => i + 1 < n,
                _ => false,
            }
        };
        let mut vis = Vec::new();
        let mut valid = false;
        let origins: Vec<(usize, usize)> = vec![(0, 2), (1, 3), (0, 3), (2, 3), (0, 1), (2, 1)];
        let mut dfs = |mut i: usize, mut j: usize, mut from: usize| -> bool {
            vis = vec![vec![false; grid[0].len()]; grid.len()];
            valid = false;
            loop {
                let mut nxt = 0;
                let origin = origins[grid[i][j] as usize - 1];
                if vis[i][j] {
                    break;
                }
                vis[i][j] = true;

                if from == origin.0 {
                    nxt = origin.1
                } else if from == origin.1 {
                    nxt = origin.0
                } else {
                    break;
                }
                if i == n - 1 && j == m - 1 {
                    valid = true;
                    break;
                }
                let diff: Vec<(i32, i32)> = vec![(0, -1), (-1, 0), (0, 1), (1, 0)];
                if check(i, j, nxt) {
                    i = (i as i32 + diff[nxt].0) as usize;
                    j = (j as i32 + diff[nxt].1) as usize;
                    from = (nxt + 2) % 4;
                }
            }
            valid
        };
        for k in 0..4 {
            if dfs(0, 0, k) {
                return true;
            }
        }
        false
    }
}

fn main() {
    println!(
        "{:?}",
        Solution::has_valid_path(vec![vec![2, 4, 3], vec![6, 5, 2]])
    );
    println!(
        "{:?}",
        Solution::has_valid_path(vec![vec![1, 2, 1], vec![1, 2, 1]])
    );
    println!("{:?}", Solution::has_valid_path(vec![vec![1, 1, 2]]));
    println!(
        "{:?}",
        Solution::has_valid_path(vec![vec![4, 3, 3], vec![6, 5, 2]])
    );
}

//
// Created by ASUS at 6/30/2025 10:58 PM
//
